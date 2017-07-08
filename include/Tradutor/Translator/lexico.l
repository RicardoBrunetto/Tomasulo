%{
#include <limits.h>
#include <string.h>
#include "grammar.tab.h"
#include "errormsg.h"
#include "util.h"

/* the maximum length of a string constant */
#define MAX_STR_CONST 16384

/* we are not going to use yyunput */
#define YY_NO_UNPUT

int 		nesting = 0;
int 		lexline = 1;
int		lexcol	= 0;

char 		string_buf[MAX_STR_CONST];
char *		string_buf_ptr;

void adjust(void);

extern YYLTYPE yylloc;

%}

%x		IN_COMMENT

digit		[0-9]
letter		[a-zA-Z]
integer		{digit}+
identifier	{letter}("_"|{letter}|{digit})*


%%

"/*"			{ adjust(); 
                          BEGIN(IN_COMMENT); nesting = 1; }
<IN_COMMENT>
{
    "/*"		{ adjust(); nesting++; }
    "*/"		{ adjust(); if ( --nesting == 0 ) BEGIN(INITIAL); }
    \n			{ adjust(); }
    <<EOF>>		{ adjust(); yyerror( "unterminated comment" ); }
    .			{ adjust(); }
}

[ \t]+			{ adjust(); }
\n			{ adjust(); }
"add"			{ adjust(); return ADD; }
"lui"			{ adjust(); return LUI; }
"slt"			{ adjust(); return SLT; }

{integer}		{
			    char * buf = (char *) malloc(20);
			    long int value;

			    adjust();

			    value = strtol( yytext, &buf, 10 );

			    if ( value == LONG_MAX || value > INT_MAX )
			    {
				yyerror( "invalid integer" );
				exit( 1 );
			    }

			    yylval.u_integer = (int) value;
			    return INTLIT;
			}
{identifier}		{
			    char * buf = (char *) malloc( ( yyleng + 1 ) * 
							  sizeof( char ) );
                            strcpy( buf, yytext );
			    yylval.u_ident = buf;

 			    adjust();  
			    return IDENT;
			}

","			{ adjust(); return COMMA; }
.			{ adjust(); yyerror( "Unknown character" ); }

%%

void adjust(void)
{
    int i;

    yylloc.first_line	= lexline;
    yylloc.first_column	= lexcol+1;

    for ( i = 0; yytext[i] != '\0'; i++ )
    {
	if ( yytext[i] == '\n' )
	{
	    lexline++;
	    lexcol = 0;
	}
	else if ( yytext[i] == '\t' )
	    lexcol += 8 - ( lexcol % 8 );
	else
	    lexcol++;
    }

    yylloc.last_line	= lexline;
    yylloc.last_column	= lexcol;
}

int yywrap(void) {}
