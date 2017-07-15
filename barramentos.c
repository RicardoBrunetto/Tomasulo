#include "include/barramentos.h"

void inicializar_barramentos(){
  CDB.dados = FLAG_VAZIO;
  CDB.endereco = FLAG_VAZIO;
  CDB.controle = FLAG_READY;

  CMB.dados = FLAG_VAZIO;
  CMB.endereco = FLAG_VAZIO;
  CMB.controle = FLAG_READY;

  PCB.dados = FLAG_VAZIO;
  PCB.endereco = FLAG_VAZIO;
  PCB.controle = FLAG_READY;

  PCLB.dados = FLAG_VAZIO;
  PCLB.endereco = FLAG_VAZIO;
  PCLB.controle = FLAG_READY;
}
