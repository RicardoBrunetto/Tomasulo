#include "util.h"

/*Retorna se é do tipo R, J ou I*/
int getTipo_instrucao(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      return d->formato;
    }
  }
  printf("\nERRO GRAVISSIMO - UTIL.c\n");
  resetProximoLinkedList(&lista_definicoes);
}

/*Função que realiza a decodificação de uma instrução (em inteiro)*/
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
      Instrucao->instruction_R->rs = rs;
      Instrucao->instruction_R->rt = rt;
      Instrucao->instruction_R->rd = rd;
      Instrucao->instruction_R->shift = sh;
      Instrucao->instruction_R->func = func;
      break;
    case TYPE_J:
      int target = target << 6; target = target >> 6;
      Instrucao->type = TYPE_J;
      Instrucao->instruction_J->opcode = opcode;
      Instrucao->instruction_J->target = target;
      break;
    case TYPE_I:
      int rs = instr >> 21; rs = rs & 31;
      int rt = instr >> 16; rt = rt & 31;
      int imm = instr << 16; imm = imm >> 16;
      Instrucao->type = TYPE_I;
      Instrucao->instruction_I->opcode = opcode;
      Instrucao->instruction_I->rs= rs;
      Instrucao->instruction_I->rt = rt;
      Instrucao->instruction_I->imm = imm;
      break;
  }
  return instrucao;
}

//TODO:
int isInconditionalJump(Instrucao * i){
  return 1;
}

/*Verifica se aquela unidade funcional é capaz de processar aquela instrução*/
int tipo_compativel(int opcode, int tipo_uf){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      if(d->tipo_uf == tipo_uf) return 1;
      return 0;
    }
  }
  printf("\nERRO GRAVISSIMO - UTIL.c\n");
  resetProximoLinkedList(&lista_definicoes);
}
