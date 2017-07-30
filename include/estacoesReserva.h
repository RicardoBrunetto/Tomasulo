#ifndef ESTACOES_RESERVA_H
#define ESTACOES_RESERVA_H

#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "barramentos.h"
#include "registradores.h"
#include "util.h"
#include "clock.h"

#define FLAG_DISPONIVEL -1
#define BRANCH_TAKEN         1
#define BRANCH_NOT_TAKEN     0

/*Definições de operações da ULA*/
#define OP_ADD    0
#define OP_AND    1
#define OP_OR     2
#define OP_NOR    3
#define OP_SLL    4
#define OP_SRL    5
#define OP_SRA    6
#define OP_SUB    7
#define OP_XOR    8
#define OP_AmeB   9
#define OP_AmaB   10
#define OP_AeqB   11
#define OP_MULs   12
#define OP_MULsHI 13
#define OP_MULu   14
#define OP_MULuHI 15
#define OP_DIV    16
#define OP_MOD    17

/*Estações de Reserva*/
EstacaoReserva * estacoes_Reserva;

void inicializar_estacoes_reserva();
void enviar_para_CDB(int indice_ER);
void er_despachar(int indice_ER);
void er_print();

#endif
