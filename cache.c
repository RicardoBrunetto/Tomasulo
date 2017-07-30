#include "include/cache.h"

#define FLAG_HIT  1
#define FLAG_MISS 0

/*As definições são internas porque o processador não tem acesso direto*/
Cache cache_dados;
Cache cache_instrucoes;

int isHit(int address){
  return FLAG_MISS;
}

int cache_read(int address){

  //CMB.controle = FLAG_READ;
  //CMB.endereco = address;
  //PCB.controle = FLAG_READY;
}

int cache_write(int address, int dado){

  // PCB.controle = FLAG_READY;
}

void cache_controller_next(){
  /*PCB precisa de algo?*/
  Dado_Barramento * d_pcb = topo_barramento(PCB);
  if(d_pcb->controle == FLAG_READY) return;


  if(!isHit(d_pcb->endereco)){ /*Houve MISS na cache*/
    /*Verifica se houve resposta da RAM pelo CMB*/
    Dado_Barramento * db = topo_barramento(CMB);
    if(db->controle == FLAG_READY){
      if(CMB.status != FLAG_READY){ /*Status tem o indice da ER que precisa do dado (indica que o dado está no barramento)*/
        /*Escreve o dado recebido no PCB para devolver ao processador*/
        alterar_topo_barramento(PCB, db->dado, db->endereco, db->controle);
        /*Torna CMB disponível*/
        alterar_topo_barramento(CMB, FLAG_VAZIO, FLAG_VAZIO, FLAG_READY);
        CMB.status = FLAG_READY;
      }else{ /*CMB disponível*/
        /*Envia requisição ao CMB*/
        alterar_topo_barramento(CMB, d_pcb->dado, d_pcb->endereco, d_pcb->controle);
        CMB.status = PCB.status;
      }
    }
  }else{
    /*//TODO: resolve o load/store na cache*/
    /*Escreve no PCB / Não altera o CMB*/
  }
}

  // if(PCB.controle == FLAG_READ){
  //   PCB.controle = FLAG_BUSY; /*Define o barramento como ocupado*/
  //   PCB.dados = cache_read(PCB.endereco); /*Escreve o dado lido da cache no endereço*/
  // }else if(PCB.controle == FLAG_WRITE){
  //   PCB.controle = FLAG_BUSY; /*Define o barramento como ocupado*/
  //   cache_write(PCB.endereco, PCB.dados); /*Escreve o dado lido da cache no endereço*/
  // }

void inicializar_cache(){
  int i;
  for(i=0; i<CACHE_LINE_COUNT; i++){
    cache_dados.linhas[i].update = 0;
    cache_instrucoes.linhas[i].update = 0;
  }
}

void cache_print(){

}

void cache_next(){
  cache_controller_next();
}
