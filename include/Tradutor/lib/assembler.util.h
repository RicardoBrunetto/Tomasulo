#ifndef ASSEMBLER_UTIL_H
#define ASSEMBLER_UTIL_H

#define FLAG_ASSEMBLER 1
#define FLAG_DEFINER   0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../LinkedList.h"
#include "../../definitions.h"
#include "../../util.h"

typedef struct{
  char * lbl_identificador;
  int lbl_offset;
}SLabel;

FILE * output;

int getNumber(char *str);

void setInstruction_R(int opcode, int rs, int rt, int rd, int shift, int func, int offset);

void setInstruction_I(int opcode, int rs, int rt, int imm, int offset);

void setInstruction_J(int opcode, int targetAddress, int offset);

void setData(int offset, int * numeros, int qtdNum);

int getOffset(LinkedList * lista, char * lbl);

void print_lista_labels(LinkedList * lista);

#endif
