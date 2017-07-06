/*-------------------------------------------------------------------------------*
 * Compilador Tiger                                                              *
 *                                                                               *
 * Parte : Frontend (Constroi AST)                                               *
 * Arq.  : hashtable.h                                                           *
 * Descr.: Implementa uma tabela hash e funções para sua manipulação.            *
 *         Nenhum algoritmo deve usar estas funções diretamente, porque          *
 *         programas com void* é muito suscetível a erros. Ao invés disto, cada  *
 *         módulo deve fazer uma função "wrapper" que conhece os tipos dos       *
 *         argumentos de cada chamada de função.                                 *
 * Autor.: Anderson Faustino da Silva                                            *
 * Atual.: 22/09/2005                                                            * 
 *                                                                               *
 * Copyright (C) 2005 Anderson Faustino da Silva                                 *
 *-------------------------------------------------------------------------------*/

#ifndef __HASHTABLE_H
#define __HASHTABLE_H

/*
 * Uma tabela
 */
typedef struct HT_table_ *HT_table;

/*
 * Dados da tabela
 */
typedef struct HT_binder_ *HT_binder;

struct HT_binder_ {
  void *key;           // chave
  void *value;         // valor
  HT_binder next;      // próxima chave (colisão)
  void *prevtop;       // topo anterior
};

/* 
 * Cria uma tabela vazia, para mapear "chaves" para "valores". 
 */
HT_table 
HT_Empty(void);

/* 
 * Inseri um mapeamento "chave"->"valor" em uma tabela, 
 * "escondendo" mas não destruindo qualquer ligações prévias para "chave".
 */
void 
HT_Enter(HT_table, 
	 void *, 
	 void *);

/* 
 * Procura pela mais recente ligação para "chave" em uma tabela .
 */
void 
*HT_Look(HT_table, 
	 void *);

/* 
 * Retira a mais recente ligação, chamando uma função para o valor (para liberar
 * memória) se o valor não é NULL, e retorna a chave. Se a função
 * é NULL, ela não é chamada.
 */
void *HT_Pop(HT_table, 
	     void (*)(void *));
/* 
 * Retira a mais recente ligação.
 */
HT_binder 
HT_Pop2(HT_table);

/* 
 * Chama uma função para cada par "chave"->"valor" em uma tabela,
 * incluindo as ligações "escondidas", em ordem a partir da ligação mais
 * recente de qualquer chave para a ligação mais antiga na tabela.
 */
void 
HT_Dump(HT_table, 
	void (*)(void *, void *));


#endif /* __TABLE_H */
