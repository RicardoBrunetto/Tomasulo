#include "assembler.util.h"

int manter_negativo(int val){
  int msb = val; msb = msb >> 31;
  if(msb == 1){
    msb = msb << 15;
    val = val << 16; val = val >> 16;
    val = val | msb;
  }
  return val;
}

int getNumber(char *str){
  int len = strlen(str), i;

  for(i=0; i<len; i++){
    if(str[i] >= 48 && str[i] <= 57)
      break;
  }

  return atoi(str+i);
}

void insertNop(int offset_Atual){
  int i, instr = 0, lines = (DATA_AMOUNT/WORD_SIZE);
  for(i=(offset_Atual + WORD_SIZE - 1); i<lines; i++){
    fwrite(&instr, WORD_SIZE, 1, output);
  }
}

void setInstruction_R(int opcode, int rs, int rt, int rd, int shift, int func, int offset){
  int instr = opcode; instr = instr << 26;
  rs = rs << 21; instr = instr | rs;
  rt = rt << 16; instr = instr | rt;
  rd = rd << 11; instr = instr | rd;
  shift = shift << 6; instr = instr | shift;
  instr = instr | func;
  fwrite(&instr, WORD_SIZE, 1, output);
}

void setInstruction_I(int opcode, int rs, int rt, int imm, int offset){
  int instr = opcode; instr = instr << 26;
  rs = rs << 21; instr = instr | rs;
  rt = rt << 16; instr = instr | rt;
  imm = imm << 16; imm = imm >> 16; instr = instr | imm;
  fwrite(&instr, WORD_SIZE, 1, output);
}

void setInstruction_J(int opcode, int targetAddress, int offset){
  int instr = opcode; instr = instr << 26;
  targetAddress = targetAddress  << 6; targetAddress = targetAddress >> 6;
  instr = instr | targetAddress;
  fwrite(&instr, WORD_SIZE, 1, output);
}

int hex_to_dec(char * hexstring){
  return ((int)strtol(hexstring, NULL, 16));
}

void setData(int offset, int * numeros, int qtdNum){
  fwrite(numeros, (qtdNum * WORD_SIZE), 1, output);
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
