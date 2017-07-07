#ifndef ESTACOES_RESERVA_H
#define ESTACOES_RESERVA_H

#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

#define QUANTIDADE_ESTACOES_RESERVA 5

/*Estruturas que o Processador Manipulará*/
typedef struct{
  Tipo_ER_UF type; //Tipo de Unidade Funcional
  int ALUOutput; //Buffer que segura a saída da Unidade Funcional
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
