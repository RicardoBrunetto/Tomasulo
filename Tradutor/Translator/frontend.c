#include <string.h>
#include <stdlib.h>
#include "frontend.h"

/*
 * Parser.
 * Definida pela ferramenta flex.
 */
int yyparse( void ); 

/*
 * Variável do flex.
 * Define entrada padrão do parser.
 */
extern FILE * yyin;  

/*
 * Variável do flex.
 */
extern int yydebug;  

/* 
 * Retorna a ávore abstrata de um determinado códigofonte 
 */

AST_exp  FE_FrontEnd(UT_string file) {
  if ( file != NULL )  {
    // extensão .tig
    strcat(file, ".tig");
    // inicia ambiente de erros
    EM_Reset(file);
    // abre arquivo com o código fonte
    yyin = fopen(file,"r");
    if (!yyin) {EM_Error(0,0, " Cannot open this file."); exit(1);}
    yydebug = 0;
    // faz o parser do código fonte
    yyparse(); 
    // retorna árvore abstrata
    return AST_root;
  }
  else return NULL;
}
