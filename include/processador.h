#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "lib/util.h"
#include "Memoria/memoria.h"
#include "Registradores/registradores.h"
#include "EstacoesReserva/estacoesReserva.h"

/*Barramento CDB*/
Barramento CDB;
/*Program Counter e Instruction Register*/
Registrador PC, IR;
/*Fila de Instruções a serem processadas*/
Fila fila_Instrucoes;
/*Banco com os 32 registradores*/
Registrador banco_Registradores[32];

/*Protótipos*/
int main();
void processador_start();
void Processador_next();
/*Protótipos do Pipeline*/
void PIPELINE_decode();

#endif
