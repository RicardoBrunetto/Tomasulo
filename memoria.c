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

void mem_init(){
  printf("\nInicializando Memoria\n");
  int i;
  for(i=0; i<MEM_SIZE; i = i+WORD_SIZE){
    mem_write(FLAG_VAZIO, i);
  }
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

void mem_next(){
  /*PCB precisa de algo?*/
  Dado_Barramento * d_cmb = topo_barramento(CMB);
  if(d_cmb->controle == FLAG_READY) return;

  if(d_cmb->controle == FLAG_READ){
    alterar_topo_barramento(CMB, mem_read(d_cmb->endereco), FLAG_VAZIO, FLAG_READY);
  }else if(d_cmb->controle == FLAG_WRITE){
    mem_write(d_cmb->dado, d_cmb->endereco);
    alterar_topo_barramento(CMB, FLAG_VAZIO, FLAG_VAZIO, FLAG_READY);
  }
}
