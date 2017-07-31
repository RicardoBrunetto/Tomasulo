#include "include/util.h"

/*Retorna a quanidade de ciclos da operação*/
int get_ciclos(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->abstract_opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      return d->ciclos;
    }
  }
  printf("\nInstrução %d não definida no arquivo def_file.txt\n", opcode);
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}

/*Retorna se é do tipo R, J ou I*/
int getTipo_instrucao(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      return d->formato;
    }
  }
  /*printf("\nInstrução %d não definida no arquivo def_file.txt\n", opcode);*/
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}

/*Verifica se aquela unidade funcional é capaz de processar aquela instrução*/
int is_uf_compativel(int opcode, int tipo_uf){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->abstract_opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      if(d->tipo_uf == tipo_uf) return 1;
      return 0;
    }
  }
  /*printf("\nInstrução %d não definida no arquivo def_file.txt\n", opcode);*/
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}

/*Define o Opcode que irá para a ER baseado no opcode e function
  Aplicável somente à instruções do tipo R*/
int get_abstract_opcode(int opcode, int funct){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
      if(d->function == funct){
        resetProximoLinkedList(&lista_definicoes);
        return d->abstract_opcode;
      }
    }
  }
  /*printf("\nInstrução %d não definida no arquivo def_file.txt\n", opcode);*/
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}

/*Retorna o mnemonico da operação*/
char * get_mnemonico(int absopcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->abstract_opcode == absopcode){
      resetProximoLinkedList(&lista_definicoes);
      return d->mnemonic;
    }
  }
  /*printf("\nInstrução %d não definida no arquivo def_file.txt\n", absopcode);*/
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}

/*Função que retorna verdadeiro (1) se a instrução puder ser processada por uma UF de Load*/
int isLoad(int absopcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->abstract_opcode == absopcode) break;
  }
  resetProximoLinkedList(&lista_definicoes);
  /*if(d == NULL) printf("\nInstrução %d não definida no arquivo def_file.txt\n", absopcode);*/
  if(d == NULL) return 0;
  if(d->tipo_uf == LOAD_UF) return 1;
  return 0;
}

/*Função que retorna verdadeiro (1) se a instrução puder ser processada por uma UF de Store*/
int isStore(int absopcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->abstract_opcode == absopcode) break;
  }
  resetProximoLinkedList(&lista_definicoes);
  /*if(d == NULL) printf("\nInstrução %d não definida no arquivo def_file.txt\n", absopcode);*/
  if(d == NULL) return 0;
  if(d->tipo_uf == STORE_UF) return 1;
  return 0;
}

int isInconditionalJump(Instrucao * i){
  return (getTipo_instrucao(i->opcode) == TYPE_J ? 1 : 0);
}

/*Retorna a especificação da instrução com aquele mnemônico*/
int get_def_mnemonico(char * mnemonico){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(!strcasecmp(d->mnemonic, mnemonico)) break;
  }
  resetProximoLinkedList(&lista_definicoes);
  /*if(d == NULL) printf("\nInstrução %s não definida no arquivo def_file.txt\n", mnemonico);*/
  return d;
}

/*Retorna a especificação da instrução com aquele abstract_opcode*/
int get_def_absopcode(int absopcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->abstract_opcode == absopcode) break;
  }
  resetProximoLinkedList(&lista_definicoes);
  /*if(d == NULL)  printf("\nInstrução %d não definida no arquivo def_file.txt\n", absopcode);*/
  return d;
}

/*Retorna se a instrução de tal opcode irá cessar a emissão*/
int is_cessar_emissao(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->abstract_opcode == opcode){
      printf("\n%d - %s - %d\n", d->abstract_opcode, d->mnemonic, d->cessa_emissao);
      resetProximoLinkedList(&lista_definicoes);
      return d->cessa_emissao;
    }
  }
  resetProximoLinkedList(&lista_definicoes);
  /*printf("\nInstrução %d não definida no arquivo def_file.txt\n", opcode);*/
  return d;
}

/*Informa se a instrução de tal opcode escreve em hi ou lo*/
int is_escrever_hi_lo(int opcode){
  switch(opcode){
    case 257: /*div*/
    case 258: /*divu*/
    case 259: /*mult*/
    case 260: /*multu*/
      return 1;
  }
  return 0;
}

int is_cessar_busca_decode(Instrucao * i){
  return (is_writter_branch(i->type == TYPE_R ? get_abstract_opcode(i->opcode, i->instruction.instruction_R.func) : get_abstract_opcode(i->opcode, i->instruction.instruction_I.rt)));
}

int is_branch(int absopcode){
  switch(absopcode){
    case 4: /*beq*/
    case 5: /*bne*/
    case 6: /*blez*/
    case 7: /*bgtz*/
    case 279: /*bgez*/
    case 280: /*bgezal*/
    case 281: /*bltzal*/
    case 282: /*bltz*/
    case 283: /*jalr*/
    case 284:  /*jr*/
      return 1;
  }
  return 0;
}

int is_writter_branch(int absopcode){
  if(absopcode == NULL) return 0;
  switch(absopcode){
    case 280: /*bgezal*/
    case 281: /*bltzal*/
    case 283: /*jalr*/
      return 1;
  }
  return 0;
}

int is_rt_destino(int absopcode){
  switch(absopcode){
    case 8:   /*addi*/
    case 9:   /*addiu*/
    case 12:  /*andi*/
    case 13:  /*ori*/
    case 14:  /*xori*/
    case 15:  /*lui*/
    case 10:  /*slti*/
    case 11:  /*sltiu*/
    case 32:  /*lb*/
    case 36:  /*lbu*/
    case 33:  /*lh*/
    case 37:  /*lhu*/
    case 35:  /*lw*/
    case 34:  /*lwl*/
    case 38:  /*lwr*/
    case 59:  /*li*/
    case 60:  /*la*/
      return 1;
  }
  return 0;
}

int is_rt_operando(int absopcode){
  switch(absopcode){
    case 4: /*beq*/
    case 6: /*blez*/
    case 7: /*bgtz*/
    case 282: /*bltz*/
    case 5: /*bne*/
    case 279: /*bgez*/
    case 40:  /*sb*/
    case 41:  /*sh*/
    case 42:  /*swç*/
    case 43:  /*sw*/
    case 46:  /*swr*/
      return 1;
  }
  return 0;
}

int filtrar_dado(int absopcode, int dado){
  switch(absopcode){
    case 32:  /*lb*/
    case 36:  /*lbu*/
    case 40:  /*sb*/
      dado = dado << 24; dado = dado >> 24;
      return dado;
    case 33:  /*lh*/
    case 37:  /*lhu*/
    case 41:  /*sh*/
      dado = dado << 16; dado = dado >> 16;
      return dado;
    case 35:  /*lw*/
    case 43:  /*sw*/
      return dado;
    case 34:  /*lwl*/
    case 42:  /*swl*/
      dado = dado << 16; dado = dado >> 16;
      return dado;
    case 38:  /*lwr*/
    case 46:  /*swr*/
      dado = dado >> 16;
      return dado;
  }
}

int is_conditionalMove(int absopcode){
  switch(absopcode){
    case 289:
    case 290:
      return 1;
  }
  return 0;
}

void limpar_fila_instrucoes(){
  limpar_fila(&fila_Instrucoes);
}

/*Procedimento que exibe as configurações carregadas do simulador*/
void show_config(){
  printf("\nInstruções Reconhecidas: %d\n", getSizeofLinkedList(lista_definicoes));
  Def * d;
  printf("*---------------------------------------------------------------------------------------------------------------*\n");
  printf("*\tMnm\t|\tOp\t|\tCycle\t|\tType\t|\tUF\t|\tFunc\t|\tAbsOp\t*\n");
  printf("*---------------------------------------------------------------------------------------------------------------*\n");
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
      printf("*\t%s\t|\t%2d\t|\t%2d\t|\t", d->mnemonic, d->opcode, d->ciclos);
      switch (d->formato) {
        case TYPE_R:
          printf("TYPE_R");
          break;
        case TYPE_I:
          printf("TYPE_I");
          break;
        case TYPE_J:
          printf("TYPE_J");
          break;
      }
      printf("\t|\t");
      switch (d->tipo_uf) {
        case ADD_UF:
          printf("ADD");
          break;
        case MUL_UF:
          printf("MUL");
          break;
        case LOAD_UF:
          printf("LOAD");
          break;
        case STORE_UF:
          printf("STORE");
          break;
      }
      printf("\t|\t");
      printf("%2d\t|\t%3d\t*\n", d->function, d->abstract_opcode);
  }
  resetProximoLinkedList(&lista_definicoes);
  printf("*---------------------------------------------------------------------------------------------------------------*\n");
  printf("\n\nQuantidade de Estações de Reserva:\nADD:\t%d\nMUL:\t%d\nLOAD:\t%d\nSTORE:\t%d\nTOTAL:\t%d\n\n", QUANTIDADE_ESTACOES_RESERVA_ADD, QUANTIDADE_ESTACOES_RESERVA_MUL, QUANTIDADE_ESTACOES_RESERVA_LOAD, QUANTIDADE_ESTACOES_RESERVA_STORE, QUANTIDADE_ESTACOES_RESERVA);
}

void show_instruction_details(char * mnemonic){
  Def * d = get_def_mnemonico(mnemonic);
  if(d == NULL) return;
  printf("*---------------------------------------------------------------------------------------------------------------*\n");
  printf("*\tMnm\t|\tOp\t|\tCycle\t|\tType\t|\tUF\t|\tFunc\t|\tAbsOp\t*\n");
  printf("*---------------------------------------------------------------------------------------------------------------*\n");
  printf("*\t%s\t|\t%2d\t|\t%2d\t|\t", d->mnemonic, d->opcode, d->ciclos);
  switch (d->formato) {
    case TYPE_R:
      printf("TYPE_R");
      break;
    case TYPE_I:
      printf("TYPE_I");
      break;
    case TYPE_J:
      printf("TYPE_J");
      break;
  }
  printf("\t|\t");
  switch (d->tipo_uf) {
    case ADD_UF:
      printf("ADD");
      break;
    case MUL_UF:
      printf("MUL");
      break;
    case LOAD_UF:
      printf("LOAD");
      break;
    case STORE_UF:
      printf("STORE");
      break;
  }
  printf("\t|\t");
  printf("%2d\t|\t%3d\t*\n", d->function, d->abstract_opcode);
  printf("*---------------------------------------------------------------------------------------------------------------*\n");
}
