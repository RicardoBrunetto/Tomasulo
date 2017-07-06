

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"

/*
 * Tamanho da tabela de símbolos.
 * Deve ser um primo.
 */
#define SIZE 109  

/*
 * Definição de um símbolo.
 */
struct S_symbol_ {
  UT_string name;
  S_symbol next;
};

/*
 * Marca um ínicio de escopo.
 */
static struct S_symbol_ marksym = {"<mark>", 0};

/*
 * Tabela de símbolos.
 */
static S_symbol hashtable[SIZE];

/*
 * Cria um novo símbolo
 */
static S_symbol S_MkSymbol(UT_string name, S_symbol next) {
  S_symbol s = UT_CheckedMalloc(sizeof(*s));
  s->name = UT_String(name);
  s->next = next;
  return s;
}

/*
 * Inicia a tabela de símbolos.
 */
static void S_InitHashTable() {
  static int initialized = 0;
  if (!initialized) {
    int t;
    initialized = 1;
    for(t=0; t<SIZE; t++) hashtable[t] = NULL;
  }
}

/*
 * Função hash
 */
static unsigned int S_Hash(char *s0) {
  unsigned int h = 0;
  char *s;
  for(s = s0; *s; s++)  
    h = h * 65599 + *s;
  return h;
}

/*
 * Verifica se duas strings são iguais.
 */
static int S_StrEq(UT_string a, UT_string b) {
  return !strcmp(a, b);
}

/*
 * Inseri um símbolo na "lista" de simbolos
 */
S_symbol S_Symbol(UT_string name) {
  int index = S_Hash(name) % SIZE;
  S_symbol syms, sym;
  
  #ifdef SYMBOL_DEBUG
  printf("Symbol for \"%s\" requested.\n", name);
  #endif

  S_InitHashTable();
  syms = hashtable[index];
  for(sym = syms; sym; sym = sym->next)
    if(S_StrEq(sym->name, name))
      return sym;
  sym = S_MkSymbol(name, syms);
  hashtable[index] = sym;
  return sym;
}

/*
 * Libera os símbolos da tabela.
 */
void S_FreeSymbols(void (*free_func)(void *)) {
  int index;
  S_symbol sym, next;
  
  S_InitHashTable();

  for(index = 0; index < SIZE; index++) {
    sym = hashtable[index];
    while(sym) {
      next = sym->next;
      free_func(sym->name);
      free(sym);
      sym = next;
    }
    hashtable[index] = NULL;
  }
}

/*
 * Retorna o "nome" do símbolo.
 */
UT_string S_Name(S_symbol sym) {
  return sym->name;
}

/*
 * Cria uma tabela vazia.
 */
S_table S_Empty(void) { 
  return HT_Empty();
}

/*
 * Inseri um símbolo (e um valor a ele associado) em uma tabela.
 */
void S_Enter(S_table t, S_symbol sym, void *value) {
  #ifdef SYMBOL_DEBUG
  printf("Symbol entered:\"%s\".\n", S_name(sym));
  #endif

  HT_Enter(t,sym,value);
}

/*
 * Procura por um símbolo na tabela.
 * Se encontrar retorna o valor a ele associado,
 * caso contrário retorna NULL.
 */
void *S_Look(S_table t, S_symbol sym) {
  return HT_Look(t,sym);
}

/*
 * Inicia um novo escopo.
 */
void S_BeginScope(S_table t) {
  S_Enter(t, &marksym, NULL);
}

/*
 * Termina um escopo.
 */
void S_EndScope(S_table t, void(*func)(void *binding)) {
  S_symbol s;

  // O valor associado a marksym é NULL, mas "func" não é chamada por
  // TAB_pop() quando o valor associado é NULL, logo isto não é um problema.

  do
    s = HT_Pop(t, func);
  while (s != &marksym);
}

/*
 * "Dumping" em uma tabela de símbolos.
 */
void S_Dump(S_table t, void (*show)(S_symbol sym, void *binding)) {
  HT_Dump(t, (void (*)(void *, void *)) show);
}

