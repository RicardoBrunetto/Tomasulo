#include "estacoesReserva.h"

void inicializar_estacoes_reserva(){
  //QUANTIDADE_ESTACOES_RESERVA = QUANTIDADE_ESTACOES_RESERVA_ADD + QUANTIDADE_ESTACOES_RESERVA_MUL + QUANTIDADE_ESTACOES_RESERVA_LOAD + QUANTIDADE_ESTACOES_RESERVA_STORE;
  estacoes_Reserva = (EstacaoReserva *) malloc(sizeof(EstacaoReserva)*QUANTIDADE_ESTACOES_RESERVA);
  int i;
  for(i=0; i<QUANTIDADE_ESTACOES_RESERVA_ADD; i++){
    estacoes_Reserva[i]->BusyBit = 0;
    estacoes_Reserva[i]->uf.type = ADD_UF;
  }
  for(; i<QUANTIDADE_ESTACOES_RESERVA_MUL; i++){
    estacoes_Reserva[i]->BusyBit = 0;
    estacoes_Reserva[i]->uf.type = MUL_UF;
  }
  for(; i<QUANTIDADE_ESTACOES_RESERVA_LOAD; i++){
    estacoes_Reserva[i]->BusyBit = 0;
    estacoes_Reserva[i]->uf.type = LOAD_UF;
  }
  for(; i<QUANTIDADE_ESTACOES_RESERVA_STORE; i++){
    estacoes_Reserva[i]->BusyBit = 0;
    estacoes_Reserva[i]->uf.type = STORE_UF;
  }
}

void er_print(){
  int indice_ER;
  printf("\n\tESTAÇÕES DE RESERVA\n");
  printf("*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
  printf("*\tIndice\t|\tTipo\t|\tBusyBit\t|\t\tOp\t|\tQj\t|\t\tVj\t|\tQk\t|\t\tVk\t|\t\t a\t*\n");
  printf("*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
  for(indice_ER = 0; indice_ER<QUANTIDADE_ESTACOES_RESERVA; indice_ER++){
    printf("*\t%2d\t|\t", indice_ER);
    switch (estacoes_Reserva[indice_ER]->uf.type) {
      case ADD_UF:
        printf("ADD");
        break;
      case MUL_UF:
        printf("MUL");
        break;
      case LOAD_UF:
        printf("LOAD");
        break;
      case STORE_UF:
        printf("STORE");
        break;
    }
    printf("\t|\t%3d\t|\t%10d\t|\t%2d\t|\t%10d\t|\t%2d\t|\t%10d\t|\t%10d\t*\n",estacoes_Reserva[indice_ER]->BusyBit, estacoes_Reserva[indice_ER]->Op, estacoes_Reserva[indice_ER]->Qj, estacoes_Reserva[indice_ER]->Vj, estacoes_Reserva[indice_ER]->Qk, estacoes_Reserva[indice_ER]->Vk, estacoes_Reserva[indice_ER]->a);
  }
  printf("*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
}
