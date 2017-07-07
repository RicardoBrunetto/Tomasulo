#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "lib/util.h"
#include "Memoria/memoria.h"
#include "lib/DQueue.h"
#include "Registrador/registrador.h"
#include "EstacoesReserva/estacoesReserva.h"

/*Definições das Dimensões dos componentes do Processador*/

/*Program Counter e Instruction Register*/
Registrador PC, IR;
/*Fila de Instruções a serem processadas*/
Fila fila_Instrucoes;

/*Protótipos*/
int main();
void processador_start();
void Processador_next();
/*Protótipos do Pipeline*/
void PIPELINE_decode();

#endif
