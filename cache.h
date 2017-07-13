#ifndef CACHE_H
#define CACHE_H

#include "definitions.h"
#include "memoria.h"
#include "barramentos.h"

#define CACHE_LINES 2048 /*São 2K linhas*/
#define CACHE_WORDS 4    /*Cada linha com 4 palavras*/

typedef struct{
  Word cache[CACHE_LINES][CACHE_WORDS];
}Cache;

#endif
