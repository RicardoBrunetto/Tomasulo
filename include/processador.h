#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "util.h"
#include "memoria.h"
#include "registradores.h"
#include "estacoesReserva.h"
#include "DQueue.h"

/*Barramento CDB*/
Barramento CDB;

/*Protótipos*/
void processador_start();
void processador_next();
void processador_print();

#endif
//4459588
