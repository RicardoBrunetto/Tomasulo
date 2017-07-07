#ifndef REGISTRADOR_H
#define REGISTRADOR_H

#include <stdio.h>
#include <stdlib.h>

#define REGISTRADOR_LIVRE -1

typedef struct reg{
  int Qi, valor;
}Registrador;

/*Banco com os 32 registradores*/
Registrador banco_Registradores[32];

void inicializar_registradores();
int reg_write(int w, int registrador);
int reg_read(int registrador);
int reg_get_status(int registrador);
int reg_change_status(int registrador, int indice_ER);
void reg_print(int reg);
void reg_banco_print();

#endif
