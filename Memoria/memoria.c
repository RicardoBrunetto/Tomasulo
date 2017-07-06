#include <stdlib.h>
#include "memoria.h"

int mem_write(Word w, int address){
  unsigned char * ptr = (unsigned char *) &w;
  int k;
  for(k=address; k<address+4; k++){
    m.vetor[k] = ptr[k%4];
  }
  return address+4;
}

Word mem_read(int address){
  unsigned int * ptr = malloc(sizeof(int));
  ptr = (unsigned int *) m.vetor + address;
  return *ptr;
}

void mem_print(){
  int i=0;
  printf("\n\tMEMORIA [int]\t\n");
  for(i=0; i<MEM_SIZE; i= i+4){
    printf("\n\t%20d", mem_read(i));
  }
  printf("\n\n");
}
