#include <stdio.h>
#include <stdlib.h>

#ifndef ESTACOES_RESERVA_H
#define ESTACOES_RESERVA_H

#define QUANTIDADE_ESTACOES_RESERVA 5

typedef enum { ADD_UF, MUL_UF, LOAD_UF, STORE_UF } Tipo_ER_UF;

/*Estruturas que o Processador Manipulará*/
typedef struct{
  Tipo_ER_UF type;
}UnidadeFuncional;

typedef struct{
  int BusyBit, Qj, Vj, Qk, Vk, a, Op;
  UnidadeFuncional uf;
}EstacaoReserva;

/*Estações de Reserva*/
EstacaoReserva estacoes_Reserva[QUANTIDADE_ESTACOES_RESERVA];

void inicializar_estacoes_reserva();
void er_print();

#endif
