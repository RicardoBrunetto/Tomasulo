#ifndef REGISTRADOR_H
#define REGISTRADOR_H

#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

/*Banco com os 32 registradores + HI e LO*/
Registrador banco_Registradores[34];

/*Program Counter, Instruction Register e Next Program Counter*/
Registrador PC, IR, NPC;

void inicializar_registradores();

int reg_write(int w, int registrador);
int reg_read(int registrador);
int reg_get_status(int registrador);
int reg_change_status(int registrador, int indice_ER);

void reg_print(int reg);
void reg_banco_print();

#endif
