/*-------------------------------------------------------------------------------*
 * Compilador Tiger                                                              *
 *                                                                               *
 * Parte : Frontend (Constroi AST)                                               *
 * Arq.  : errormsg.h                                                            *
 * Descr.: Utilitário para manipulação de mensagens de erros (Cabeçalho)         *
 * Autor.: Anderson Faustino da Silva                                            *
 * Atual.: 22/09/2005                                                            * 
 *                                                                               *
 * Copyright (C) 2005 Anderson Faustino da Silva                                 *
 *-------------------------------------------------------------------------------*/

#ifndef ERRORMSG_H
#define ERRORMSG_H

#include "util.h"

/* 
 * Flag para indicar erro 
 */
UT_bool EM_anyErrors;

/* 
 * Emite mensagem de erro 
 */
void 
EM_Error(int, 
	 int, 
	 UT_string,
	 ...); 

/* 
 * Inicializa variáveis de erro 
 */ 
void 
EM_Reset(UT_string); 

/*
 * Erro gerado pelo parser 
 */
void yyerror(); 

#endif
