#include "include/cache.h"

#define FLAG_HIT  1
#define FLAG_MISS 0

/*As definições são internas porque o processador não tem acesso direto*/
Cache cache_dados;
Cache cache_instrucoes;

int cache_read(int address){

  CMB.controle = FLAG_READ;
  CMB.endereco = address;
  //PCB.controle = FLAG_READY;
}

int cache_write(int address, int dado){

  PCB.controle = FLAG_READY;
}

void cache_controller_next(){
  if(PCB.controle == FLAG_READ){
    PCB.controle = FLAG_BUSY; /*Define o barramento como ocupado*/
    PCB.dados = cache_read(PCB.endereco); /*Escreve o dado lido da cache no endereço*/
  }else if(PCB.controle == FLAG_WRITE){
    PCB.controle = FLAG_BUSY; /*Define o barramento como ocupado*/
    cache_write(PCB.endereco, PCB.dados); /*Escreve o dado lido da cache no endereço*/
  }
}

void inicializar_cache(){
  int i;
  for(i=0; i<CACHE_LINE_COUNT; i++){
    cache_dados.linhas[i].update = 0;
    cache_instrucoes.linhas[i].update = 0;
  }
}

void cache_next(){
  cache_controller_next();
}
