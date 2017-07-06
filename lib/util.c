#include "util.h"

/*Retorna se é do tipo R, J ou I*/
int getTipo_instrucao(int opcode){
  return 0;
}

Instrucao * decodificar(int instr){
  int opcode = instr >> 26; opcode = opcode & 63;
  int tipo = getTipo_instrucao(opcode);
  Instrucao * instrucao = (Instrucao *)malloc(sizeof(Instrucao));
  switch(tipo){
    case TYPE_R:
      int rs = instr >> 21; rs = rs & 31;
      int rt = instr >> 16; rt = rt & 31;
      int rd = instr >> 11; rd = rd & 31;
      int sh = instr >> 6; sh = sh & 31;
      int func = instr & 63;
      Instrucao->type = TYPE_R;
      Instrucao->instruction_R->opcode = opcode;
      Instrucao->instruction_R->rd = rd;
      Instrucao->instruction_R->rs = rs;
      Instrucao->instruction_R->rt = rt;
      Instrucao->instruction_R->shift = sh;
      Instrucao->instruction_R->func = func;
      break;
    case TYPE_J:
      
    case TYPE_I:
      break;
  }
  // mágica
  return 0;
}

int isInconditionalJump(Instrucao * i){
  return 1;
}

/*Verifica se aquela unidade funcional é capaz de processar aquela instrução*/
int tipo_compativel(int tipo_instrucao, int tipo_uf){
  return 1;
}


/*Procedimento que lê o arquivo de definições e os carrega*/
