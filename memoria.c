#include <stdlib.h>
#include "include/memoria.h"

/*A memória*/
/*A definição é interna pois nenhum componente tem acesso direto*/
Memoria m;

int mem_write(Word w, int address){
  unsigned char * ptr = (unsigned char *) &w;
  int k, i = 0;
  for(k=address; k<address+WORD_SIZE; k++)
    m.vetor[k] = ptr[i++];
  return address+WORD_SIZE;
}

Word mem_read(int address){
  Word * ptr = malloc(sizeof(Word));
  ptr = (Word *) (m.vetor + address);
  return *ptr;
}

void mem_print(){
  int i=0;
  printf("\n\tMemoria [int]\t\n");
  for(i=0; i<MEM_SIZE; i= i+WORD_SIZE){
    if(i % 20 == 0) printf("\n");
    printf("\t%13d", mem_read(i));
  }
  printf("\n\n");
}
