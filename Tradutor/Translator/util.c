

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"

/*
 * Usado para definir o nível de uma variável.
 */
int UT_level = -1;

/*
 * Alocação de memória.
 */
void *UT_CheckedMalloc(int len) {
  void *p = malloc(len);
  if (!p) {
    fprintf(stderr,"\nRan out of memory!\n");
    exit(1);
  }
  return p;
}

/*
 * Cria uma string.
 */
UT_string UT_String(char *s) {
  UT_string p = UT_CheckedMalloc(strlen(s)+1);
  strcpy(p,s);
  return p;
}

/*
 * Cria uma lista de símbolos lógicos.
 */
UT_boolList UT_BoolList(UT_bool head, UT_boolList tail) { 
  UT_boolList list = UT_CheckedMalloc(sizeof(*list));
  list->head = head;
  list->tail = tail;
  return list;
}
