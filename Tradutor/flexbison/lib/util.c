
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int potencias[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648};

int binaryToInteger(char * binary){
  int size = strlen(binary), i, integer = 0;
  for(i=0; i<size; i++){
    integer += (potencias[i] * (binary[size-1-i]-'0'));
  }
  return integer;
}

int getNumber(char *str){
  int len = strlen(str), i;

  for(i=0; i<len; i++){
    if(str[i] >= 48 && str[i] <= 57)
      break;
  }

  return atoi(str+i);
}

char * integerToBinary(int integer, int strSize, char * str){
  unsigned int u_i = 0;
  int i            = 0;
  str = malloc(sizeof(char)*strSize+1);

  u_i = (unsigned int)integer;
  for(i=0; i<strSize; ++i) {
     int shifted = (u_i >> i);
     str[(strSize-1)-i] = (shifted&1)?'1':'0';
  }

  str[strSize] = (char)'\0';
  return str;
}

void insertNop(int quantidade){
  printf("\n00000000000000000000000000000000\n");
}

void setInstruction_R(char* opcode, char* rs, char* rt, char* rd, char* shift, char* func){
  char instr[32] = "";
  strcat(instr, opcode);
  strcat(instr, rs);
  strcat(instr, rt);
  strcat(instr, rd);
  strcat(instr, shift);
  strcat(instr, func);
  printf("\nInstrução tipo R: %s\tInteiro: %i\n", instr, binaryToInteger(instr));
}

void setInstruction_I(char* opcode, char* rs, char* rt, char* imm){
  char instr[32] = "";
  strcat(instr, opcode);
  strcat(instr, rs);
  strcat(instr, rt);
  strcat(instr, imm);
  printf("\nInstrução tipo I: %s\tInteiro: %i\n", instr, binaryToInteger(instr));
}

void setInstruction_J(char* opcode, char* targetAddress){
  char instr[32] = "";
  strcat(instr, opcode);
  strcat(instr, targetAddress);
  printf("\nInstrução tipo J: %s\tInteiro: %i\n", instr, binaryToInteger(instr));
}

void setData(int offset, char ** numeros, int qtdNum){
  int i;
  for(i=0; i<qtdNum; i++){
    printf("\n%i, %i, %s\n", offset, qtdNum, numeros[i]);
  }
}
