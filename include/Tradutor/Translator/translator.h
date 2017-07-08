#ifndef _TRANSLATOR_H_
#define _TRANSLATOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"       /* funções auxiliares */
#include "errormsg.h"   /* erro */
#include "absyn.h"      /* árvore abstrata */

/*
 * Variável do flex.
 * Define entrada padrão do parser.
 */
extern FILE * yyin;  

/*
 * Variável do flex.
 */
extern int yydebug;  

AST_program T_CreateAST(UT_string);

AST_bin T_Asm2Bin(AST_program);

void T_WriteBin(AST_bin);

#endif
