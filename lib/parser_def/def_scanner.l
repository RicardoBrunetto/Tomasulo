%{
#include "parser.tab.h"
%}
%%

"," { return VIRG; }
":" { return DOISPONTOS; }
"(" { return ABRE_PAR; }
")" { return FECHA_PAR; }

[0-9]+ { yylval = atoi(yytext); return VAL; }
[a-zA-Z_][a-zA-Z0-9_]* { return LBL; }
[\n]+ {return PL;}
[ \t]
"#".*

. { /*printf("Mystery character %c\n", *yytext); */}
%%
