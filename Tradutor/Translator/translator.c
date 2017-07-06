#include "translator.h"


/*
 * Parser.
 * Definida pela ferramenta flex.
 */
int yyparse( void ); 


/* 
 * Retorna a ávore abstrata de um determinado código fonte 
 */
AST_program T_CreateAST(UT_string file) {
  if ( file != NULL )  {
    // extensão .tig
    strcat(file, ".asm");
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

/*
 * Converte Assembly para Binário
 */
AST_bin T_Asm2Bin(AST_program program) {


}

/*
 * Escreve representação binária em um arquivo
 */
void T_WriteBin(AST_bin bin) {

}
