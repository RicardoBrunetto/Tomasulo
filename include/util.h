#ifndef PROC_UTIL_H
#define PROC_UTIL_H

#include <stdio.h>
#include <string.h>
#include "definitions.h"

int getTipo_instrucao(int opcode);
int isInconditionalJump(Instrucao * i);
int tipo_compativel(int tipo_instrucao, int tipo_uf);
#endif
