#include "cache.h"

#define FLAG_HIT  1
#define FLAG_MISS 0

/*As definições são internas porque o processador não tem acesso direto*/
Cache cache_dados;
Cache cache_instrucoes;

int cache_read(int address){
  
  Processador_Cache.controle = FLAG_READY;
}

int cache_write(){

  Processador_Cache.controle = FLAG_VAZIO;
}

void cache_controller_next(){
  if(Processador_Cache.controle == FLAG_READ){
    Processador_Cache.controle = FLAG_BUSY; /*Define o barramento como ocupado*/
    Processador_Cache.dado = cache_read(Processador_Cache.dado); /*Escreve o dado lido da cache no endereço*/
  }else if(Processador_Cache.controle == FLAG_WRITE){
    Processador_Cache.controle = FLAG_BUSY; /*Define o barramento como ocupado*/
    Processador_Cache.dado = cache_write(Processador_Cache.dado); /*Escreve o dado lido da cache no endereço*/
  }
}

void cache_next(){
  cache_read();
  cache_write();
}
