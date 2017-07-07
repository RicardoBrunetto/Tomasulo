#include <stdio.h>
#include <string.h>

#ifndef MEMORIA_H
#define MEMORIA_H

#define MEM_SIZE 20

typedef unsigned char Byte;
typedef unsigned int Word;

typedef struct{
    Byte vetor[MEM_SIZE];
}Memoria;

/*A memória*/
Memoria m;

Word mem_read(int address);
int mem_write(Word w, int address);
void mem_print();

#endif
