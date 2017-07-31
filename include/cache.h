#ifndef CACHE_H
#define CACHE_H

#include "barramentos.h"
#include "memoria.h"

#define CACHE_LINE_COUNT 2048 /*São 2K linhas*/
#define CACHE_LINE_SIZE  4    /*Cada linha com 4 palavras*/
#define BIT_UPDATE_SET   1
#define BIT_UPDATE_UNSET 0

typedef struct{
  Byte campos[CACHE_LINE_SIZE][WORD_SIZE];
  int tag;
  int update; /*Poderia ser um bit*/
}Linha;


/*Barramento RAM-Cache*/
struct dectag {
  unsigned int byte   : 32;
  unsigned int b32_63  : 32;
  unsigned int b64_95  : 32;
};
typedef union{
  struct dectag bits;
  int valor;
};



typedef struct{
  Linha linhas[CACHE_LINE_COUNT];
}Cache;

void inicializar_cache();
void cache_print();
void cache_next();
void cache_controller_next();

#endif
