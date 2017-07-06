/*-------------------------------------------------------------------------*
 * Compilador Tiger                                                        *
 *                                                                         *
 * Parte : Frontend (Constroi AST)                                         *
 * Arq.  : symbol.h                                                        *
 * Descr.: Simbolos e tabela de símbolos (Cabeçalho)                       *
 * Autor.: Anderson Faustino da Silva                                      *
 * Atual.: 22/09/2005                                                      * 
 *                                                                         *
 * Copyright (C) 2005 Anderson Faustino da Silva                           *
 *-------------------------------------------------------------------------*/

#ifndef SYMBOL_H
#define SYMBOL_H

#include "util.h"
#include "hashtable.h"

/*
 * Definição de tipos.
 */

typedef struct S_symbol_ *S_symbol;
typedef struct S_symbolList_ *S_symbolList;
typedef struct HT_table_ *S_table;

/*
 * Lista de símbolos
 */
struct S_symbolList_ {
  S_symbol head; 
  S_symbolList tail;
};


/* 
 * Cria um símbolo único a partir de uma string.  
 * Diferentes chamadas para S_Symbol("foo") irão gerar o mesmo valor de
 * S_symbol, mesmo se as strings "foo" estão em diferentes posições de memória.
 */
S_symbol
S_Symbol(UT_string);

/* 
 * Libera toda memória usado pelos símbolos. Esta função deve ser
 * chamada após a destruição dos símbolos da tabela através de
 * repetidas chamadas a 'S_endScope()'.
 */
void 
S_FreeSymbols(void (*free_func)(void *));

/* 
 * Extrai a string de um símbolo. 
 */
UT_string 
S_Name(S_symbol);


/* 
 * Cria uma nova tabela
 */
S_table 
S_Empty(void);

/* 
 * Armazena uma ligação "sym->value" em "t", "ocultando" mas não apagando
 * qualquer ligação prévia de "sym".
 */
void 
S_Enter(S_table, 
	S_symbol, 
	void *);

/* 
 * Look up the most recent binding of "sym" in "t", or return NULL
 * if sym is unbound.
 */
void 
*S_Look(S_table, 
	S_symbol);

/* Start a new "scope" in "t". Scopes are nested. */
void 
S_BeginScope(S_table);

/* 
 * Remove todas ligações novas a partir do início do escopo corrente,
 * chamando "free_func" em cada ligação quando esta não é NULA
 * (para liberá-la), e termina o escopo corrente.
 * O símbolo não é apagado, ele é ainda disponível.
 */
void 
S_EndScope(S_table, 
	   void(*free_func)(void *));

/*
 * "Dumping" em uma tabela de símbolos.
 */
void 
S_Dump(S_table, 
       void (*show)(S_symbol, void *));

#endif /* __SYMBOL_H */
