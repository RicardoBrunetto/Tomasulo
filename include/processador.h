#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "util.h"
#include "memoria.h"
#include "registradores.h"
#include "estacoesReserva.h"
#include "DQueue.h"


/*Barramento CDB*/
Barramento CDB;
/*Program Counter e Instruction Register*/
Registrador PC, IR;
/*Fila de Instruções a serem processadas*/
Fila fila_Instrucoes;

/*Protótipos*/
void processador_start();
void processador_next();
void processador_print();

#endif
