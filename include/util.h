#ifndef PROC_UTIL_H
#define PROC_UTIL_H

#include <stdio.h>
#include <string.h>
#include "definitions.h"

int get_ciclos(int opcode);
int getTipo_instrucao(int opcode);
int tipo_compativel(int opcode, int tipo_uf);
int get_abstract_opcode(int opcode, int funct);
int isLoad(int opcode);
int isStore(int opcode);
int isInconditionalJump(Instrucao * i);
void show_config();
void show_instruction_details(char * mnemonic);
int get_def_mnemonico(char * mnemonico);

#endif
