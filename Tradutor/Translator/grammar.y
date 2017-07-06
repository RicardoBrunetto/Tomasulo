%{
#include <string.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"

/*
 * Declarações externas
 */
  int	yylex( void );

%}

%union  {
  char                 *u_ident;
  int                   u_integer;
  char                 *u_string;
  //struct AST_data_     *u_data;
  //struct AST_dataList_ *u_dataList;
  //struct AST_text_     *u_text;
  //struct AST_textList_ *u_textList;
}

%token <u_ident>   IDENT
%token <u_integer> INTLIT
%token <u_string>  STRINGLIT

%token ADD LUI SLT
%token COMMA

%type <u_string>      dataSection
%type <u_string>      textSection
%type <u_string>      instSeq
%type <u_string>      inst
%type <u_string>      identifier

%%

program:  dataSection textSection
			{

			}
		;

dataSection:            /* seção vazia */
			{
			  $$ = NULL;
			}
		;

textSection:      /* nenhuma declaração */
                        {
                          //$$ = NULL;
                        }
                  /* sequencia de declarações */
                | instSeq
                        {
                          //$$ = $1;
                        }
                ;

                  /* uma instrução apenas */
instSeq:          inst
			{
			  //$$ = ASM_InstList($1,NULL);
			}
                  /* várias instruções */
		| instSeq inst
			{
			  //$$ = AST_CatInstList($1, ASM_InstList($2,NULL));
			}
		;

                  /* Aritmética e lógica */
inst:             alInst
			{
			  //$$ = $1;
			}
                  /* Manipulação de constante */
		| cmInst
			{
			  //$$ = $1;
			}
                  /* Comparação */
		| cInst
			{
			  // $$ = $1;
			}
		;

                  /* add rd, rs, rt */
alInst:          ADD identifier
			{
			  printf("Instrução: ADD\n");
			  printf("Linha: %i Coluna: %i Identificador: %s\n", @1.first_line, @1.first_column, $2);
			  //$$ = AST_TypeDec(@1.first_line, @1.first_column, S_Symbol($2),$4, AST_level);
			}
		;

                 /* lui rt, imm */
cmInst:          LUI identifier
			{
			  //$$ = AST_TypeDec(@1.first_line, @1.first_column, S_Symbol($2),$4, AST_level);
			}
		;

                 /* slt rd, rs, rt */
cInst:          SLT identifier
			{
			  //$$ = AST_TypeDec(@1.first_line, @1.first_column, S_Symbol($2),$4, AST_level);
			}
		;


                  /* identificador */
identifier:       IDENT
			{
			  $$ = $1;
			}
		;
%%
