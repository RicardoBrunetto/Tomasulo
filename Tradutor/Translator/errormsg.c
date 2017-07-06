
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "errormsg.h"

/* 
 * Nome do arquivo .tig
 */
static UT_string fileName = "";

/*
 * Linha do código fonte onde ocorre o erro.
 */
extern int lexline;
/*
 * Coluna do código fonte onde ocorre o erro.
 */
extern int lexcol;


/* 
 * Emite uma mensagem de erro 
 */
void EM_Error(int line, int col, char *message,...) {
  va_list ap;
 
  EM_anyErrors=TRUE;
  
  if (fileName) fprintf(stderr,"%s ",fileName);
  if (line) fprintf(stderr,"(%d, %d): ", line, col);
  va_start(ap,message);
  vfprintf(stderr, message, ap);
  va_end(ap);
  fprintf(stderr,"\n");
  
}

/* 
 * Inicializa variáveis de erro 
 */
void EM_Reset(UT_string fname) {
  fileName=fname;
}

/* 
 * Erro gerado pelo parser 
 */
void yyerror(UT_string str) {
  EM_Error(lexline, lexcol, str);
}
