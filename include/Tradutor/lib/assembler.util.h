#ifndef ASSEMBLER_UTIL_H
#define ASSEMBLER_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../LinkedList.h"

static int potencias[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648};

int binaryToInteger(char * binary);

int getNumber(char *str);

char * integerToBinary(int integer, int strSize, char * str);

void setInstruction_R(char* opcode, char* rs, char* rt, char* rd, char* shift, char* func);

void setInstruction_I(char* opcode, char* rs, char* rt, char* imm);

void setInstruction_J(char* opcode, char* targetAddress);

void setData(int offset, char ** numeros, int qtdNum);

int getOffset(LinkedList * lista, char * lbl);

#endif
