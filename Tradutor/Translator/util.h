/*-------------------------------------------------------------------------*
 * Compilador Tiger                                                        *
 *                                                                         *
 * Parte : Frontend (Constroi AST)                                         *
 * Arq.  : util.h                                                          *
 * Descr.: Funções Auxiliares (Cabeçalho)                                  *
 * Autor.: Anderson Faustino da Silva                                      *
 * Atual.: 22/09/2005                                                      * 
 *                                                                         *
 * Copyright (C) 2005 Anderson Faustino da Silva                           *
 *-------------------------------------------------------------------------*/

#ifndef _UTIL_H_
#define _UTIL_H_

#include <assert.h>

/*
 * Definição de TRUE
 */
#define TRUE 1

/*
 * Definição de FALSE
 */
#define FALSE 0


/*
 * String
 */
typedef char *UT_string;

/*
 * Lógico
 */
typedef char UT_bool;
typedef char UT_boolean;

/*
 * Lista de símbolos ógicos.
 */
typedef struct UT_boolList_ *UT_boolList;
struct UT_boolList_ {
  UT_bool head; 
  UT_boolList tail;
};

/*
 * Pilha (lista) de inteiros.
 */
typedef struct UT_stackInt_ *UT_stackInt;
struct UT_stackInt_ {
  int head; 
  UT_stackInt tail;
};

/*
 * Usado para definir o nível de uma variável.
 */
extern int UT_level;

/*
 * Alocação de memória.
 */
void 
*UT_CheckedMalloc(int);

/*
 * Cria uma string.
 */
UT_string 
UT_String(char *);

/*
 * Cria uma lista de símbolos lógicos.
 */
UT_boolList 
UT_BoolList(UT_bool, 
	    UT_boolList);

#endif
