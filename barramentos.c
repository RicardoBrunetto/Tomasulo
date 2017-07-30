#include "include/barramentos.h"

void inicializar_barramentos(){
  CDB.status = FLAG_READY;
  CDB.fila_barramento = (Fila *) malloc(sizeof(Fila));
  inicializar_fila(CDB.fila_barramento);

  CMB.status = FLAG_READY;
  CMB.fila_barramento = (Fila *) malloc(sizeof(Fila));
  inicializar_fila(CMB.fila_barramento);
  inserir_no_barramento(CMB, FLAG_VAZIO, FLAG_VAZIO, FLAG_READY);

  PCB.status = FLAG_READY;
  PCB.fila_barramento = (Fila *) malloc(sizeof(Fila));
  inicializar_fila(PCB.fila_barramento);
  inserir_no_barramento(PCB, FLAG_VAZIO, FLAG_VAZIO, FLAG_READY);
}

void inserir_no_barramento(Barramento b, int dado, int endereco, int controle){
  Dado_Barramento * d = (Dado_Barramento *) malloc(sizeof(Dado_Barramento));
  d->controle = controle;
  d->dado = dado;
  d->endereco = endereco;
  inserir_fila(b.fila_barramento, d);
}

void inserir_Dado_no_Barramento(Barramento b, Dado_Barramento * d){
  inserir_fila(b.fila_barramento, d);
}

Dado_Barramento * get_topo_barramento(Barramento b){
  return ((Dado_Barramento * ) remover_fila(b.fila_barramento));
}

Dado_Barramento * topo_barramento(Barramento b){
  return ((Dado_Barramento * ) get_topo_fila(b.fila_barramento));
}

void alterar_topo_barramento(Barramento b, int dado, int endereco, int controle){
  Dado_Barramento * d = (Dado_Barramento *)malloc(sizeof(Dado_Barramento));
  d->controle = controle;
  d->dado = dado;
  d->endereco = endereco;
  limpar_fila(b.fila_barramento);
  inserir_fila(b.fila_barramento, d);
}
