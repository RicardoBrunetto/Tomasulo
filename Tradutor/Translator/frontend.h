/*-------------------------------------------------------------------------------*
 * Compilador Tiger                                                              *
 *                                                                               *
 * Parte : Frontend (Constroi AST)                                               *
 * Arq.  : frontend.h                                                            *
 * Descr.: Análise léxica e gramatical do código fonte. Se não existir erros,    *
 *         será retornado uma árvore abstrata do código fonte.  (Cabeçalho)      *
 * Autor.: Anderson Faustino da Silva                                            *
 * Atual.: 22/09/2005                                                            * 
 *                                                                               *
 * Copyright (C) 2005 Anderson Faustino da Silva                                 *
 *-------------------------------------------------------------------------------*/

#ifndef FRONTEND_H
#define FRONTEND_H

#include <stdio.h>
#include "util.h"    
#include "errormsg.h" 
#include "absyn.h"    

/* 
 * Retorna a ávore abstrata de um determinado códigofonte 
 */
AST_exp 
FE_FrontEnd(UT_string); 

#endif /* _MAIN_FRONTEND */
