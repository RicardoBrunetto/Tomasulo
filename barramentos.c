#include "include/barramentos.h"

void inicializar_barramentos(){
  CDB.dados = FLAG_VAZIO;
  CDB.endereco = FLAG_VAZIO;
  CDB.controle = FLAG_READY;
  inicializar_fila(CDB.fila_barramento);

  CMB.dados = FLAG_VAZIO;
  CMB.endereco = FLAG_VAZIO;
  CMB.controle = FLAG_READY;
  inicializar_fila(CMB.fila_barramento);

  PCB.dados = FLAG_VAZIO;
  PCB.endereco = FLAG_VAZIO;
  PCB.controle = FLAG_READY;
  inicializar_fila(PCB.fila_barramento);
}
