
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "hashtable.h"

/*
 * Tamanho da tabela
 */
#define TABSIZE 127

/*
 * Tabela
 */
struct HT_table_ {
  HT_binder table[TABSIZE];
  void *top;
};


/*
 * Cria uma nova ligação.
 */
static HT_binder HT_Binder(void *key, void *value, HT_binder next, void *prevtop) {
  HT_binder b = UT_CheckedMalloc(sizeof(*b));
  b->key     = key;
  b->value   = value;
  b->next    = next;
  b->prevtop = prevtop; 
  return b;
}

/*
 * Libera uma ligação.
 */
static void HT_FreeBinder(HT_binder b) {
  free(b);
}

/*
 * Cria uma tabela vazia, para mapear "chaves" para "valores".
 */
HT_table HT_Empty(void) {
  HT_table t = UT_CheckedMalloc(sizeof(*t));
  int i;
  t->top = NULL;
  for(i = 0; i < TABSIZE; i++)
    t->table[i] = NULL;
  return t;
}

/* 
 * Inseri um mapeamento "chave"->"valor" em uma tabela, 
 * "escondendo" mas não destruindo qualquer ligações prévias para "chave".
 *
 * A conversão de um ponteiro para um inteiro na expressão
 *   ((unsigned) key) % TABSIZE
 * pode lidar com uma mensagem de warning. Porém, o código é seguro,
 * e irá operar corretamente.  Esta linha é apenas um hashing
 * de um ponteriro em um inteiro, e não importa como a conversão
 * é feita, a medida que isto é feito consistentemente, um
 * aceitável índice de uma tabela será gerado.
 */

void HT_Enter(HT_table t, void *key, void *value) {
  int index;
  
  if (!t || !key) printf("erro:%x %x\n", t, key);
  assert(t && key);
  
  index = ((unsigned) key) % TABSIZE;

  t->table[index] = HT_Binder(key, value, t->table[index], t->top);
  t->top          = key;
}

/* 
 * Procura pela mais recente ligação para "chave" em uma tabela .
 */
void *HT_Look(HT_table t, void *key) {
  int index;
  HT_binder b;

  if (!key) printf("HT -> chave nula\n");

  assert(t && key);
  index = ((unsigned) key) % TABSIZE;

  for(b = t->table[index]; b; b = b->next)
    if(b->key == key)
      return b->value;

  /* chave não encontrada, nenhum valor retornado */
  return NULL;
}

/* 
 * Retira a mais recente ligação, chamando uma função para o valor (para liberar
 * memória) se o valor não é NULL, e retorna a chave. Se a função
 * é NULL, ela não é chamada.
 */
void *HT_Pop(HT_table t, void(*free_func)(void *value)) {
  void *key;
  HT_binder b;
  int index;

  assert (t);

  key = t->top;

  if (!key)
    return NULL;

  index = ((unsigned) key) % TABSIZE;
  b = t->table[index];
  assert(b);

  if(free_func && b->value)
    free_func(b->value);

  t->table[index] = b->next;
  t->top          = b->prevtop;

  HT_FreeBinder(b);

  return key;
}

/* 
 * Retira a mais recente ligação.
 */
HT_binder HT_Pop2(HT_table t) {
  void *key;
  HT_binder b;
  int index;

  assert (t);

  key = t->top;

  if (!key)
    return NULL;

  index = ((unsigned) key) % TABSIZE;
  b = t->table[index];
  assert(b);

  t->table[index] = b->next;
  t->top          = b->prevtop;

  return b;
}

/* 
 * Chama a função show para cada par "key"->"value" em uma tabela,
 * incluindo as ligações "escondidas", em ordem a partir da ligação mais
 * recente de qualquer chave para a ligação mais antiga na tabela.
 */
void HT_Dump(HT_table t, void (*show)(void *key, void *value)) {
  void *k = t->top;
  int index = ((unsigned) k) % TABSIZE;
  HT_binder b = t->table[index];

  if(b == NULL) return;

  t->table[index] = b->next;
  t->top          = b->prevtop;

  show(b->key, b->value);

  HT_Dump(t, show);

  assert(t->top == b->prevtop && t->table[index] == b->next);

  t->top          = k;
  t->table[index] = b;
}

