%{
#include "def_parser.tab.h"

%}
%%

"#".*.[\n]

"&" { return ECOM; }
"," { return VIRG; }
":" { return DOISPONTOS; }
"(" { return ABRE_PAR; }
")" { return FECHA_PAR; }

[0-9]+ { yylval.integer_value = atoi(yytext); return VAL; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.string_value = strdup(yytext); return LBL; }
[\n]+ {return PL;}
[ \t]

. { /*printf("Mystery character %c\n", *yytext); */}
%%
