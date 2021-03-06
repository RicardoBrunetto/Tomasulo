#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdio.h>
#include <string.h>

#include "definitions.h"
#include "barramentos.h"

#define MEM_SIZE 536870912 /*512M*/
//#define MEM_SIZE 1024 /*120 B*/

typedef unsigned char Byte;
typedef unsigned int Word;

typedef struct{
    Byte vetor[MEM_SIZE];
}Memoria;

Word mem_read(int address);
int mem_write(Word w, int address);
void mem_print();
void mem_next();
void mem_init();

#endif
