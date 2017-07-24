#include "assembler.util.h"

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

void setInstruction_R(int opcode, int rs, int rt, int rd, int shift, int func){
  int instr = opcode; instr = instr << 26;
  rs = rs << 21; instr = instr | rs;
  rt = rt << 16; instr = instr | rt;
  rd = rd << 11; instr = instr | rd;
  shift = shift << 6; instr = instr | shift;
  instr = instr | func;
  printf("\nInstrução tipo R:\tInteiro: %i\n", instr);
}

void setInstruction_I(int opcode, int rs, int rt, int imm){
  printf("\nop: %d\trs: %d\trt: %d\timm: %d\n", opcode, rs, rt, imm);
  int instr = opcode; instr = instr << 26;
  rs = rs << 21; instr = instr | rs;
  rt = rt << 16; instr = instr | rt;
  imm = imm << 16; imm = imm >> 16; instr = instr | imm;
  printf("\nInstrução tipo I:\tInteiro: %i\n", instr);
}

void setInstruction_J(int opcode, int targetAddress){
  int instr = opcode; instr = instr << 26;
  targetAddress = targetAddress  << 6; targetAddress = targetAddress >> 6;
  instr = instr | targetAddress;
  printf("\nInstrução tipo J:\tInteiro: %i\n", instr);
}

int hex_to_dec(char * hexstring){
  return ((int)strtol(hexstring, NULL, 16));
}


void setData(int offset, int * numeros, int qtdNum){
  int i;
  for(i=0; i<qtdNum; i++){
    printf("\n%d, %d, %d\n", offset, qtdNum, numeros[i]);
  }
}

int getOffset(LinkedList * lista, char * lbl){
  SLabel * d;
  while((d = (SLabel *)getProximoLinkedList(lista)) != NULL){
    if(!strcasecmp(d->lbl_identificador, lbl)){
      resetProximoLinkedList(lista);
      return d->lbl_offset;
    }
  }
  resetProximoLinkedList(lista);
}


/*Exibe a lista de Labels*/
void print_lista_labels(LinkedList * lista){
  show_config();
  SLabel * d;
  while((d = (SLabel *)getProximoLinkedList(lista)) != NULL)
    printf("Identificador: %s\tOffset: %d\n", d->lbl_identificador, d->lbl_offset);
  resetProximoLinkedList(lista);
}
