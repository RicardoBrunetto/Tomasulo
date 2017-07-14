#include <stdlib.h>
#include "include/memoria.h"

/*A memória*/
/*A definição é interna pois nenhum componente tem acesso direto*/
Memoria m;

int mem_write(Word w, int address){
  unsigned char * ptr = (unsigned char *) &w;
  int k;
  for(k=address; k<address+WORD_SIZE; k++){
    m.vetor[k] = ptr[k%WORD_SIZE];
  }
  return address+WORD_SIZE;
}

Word mem_read(int address){
  unsigned int * ptr = malloc(sizeof(Word));
  ptr = (unsigned int *) m.vetor + address;
  return *ptr;
}

void mem_print(){
  int i=0;
  printf("\n\tMEMORIA [int]\t\n");
  for(i=0; i<MEM_SIZE; i= i+WORD_SIZE){
    printf("\n\t%20d", mem_read(i));
  }
  printf("\n\n");
}
