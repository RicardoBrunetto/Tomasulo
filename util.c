#include "include/util.h"

/*Retorna a quanidade de ciclos da operação*/
int get_ciclos(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      return d->ciclos;
    }
  }
  printf("\nInstrução não definida no arquivo def_file.txt\n");
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
  printf("\nInstrução não definida no arquivo def_file.txt\n");
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
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
  printf("\nInstrução não definida no arquivo def_file.txt\n");
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
  printf("\nInstrução não definida no arquivo def_file.txt\n");
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
  printf("\nInstrução não definida no arquivo def_file.txt\n");
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}

/*Função que retorna verdadeiro (1) se a instrução puder ser processada por uma UF de Load*/
int isLoad(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      if(d->tipo_uf == LOAD_UF) return 1;
      return 0;
    }
  }
  printf("\nInstrução não definida no arquivo def_file.txt\n");
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}

/*Função que retorna verdadeiro (1) se a instrução puder ser processada por uma UF de Store*/
int isStore(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
      resetProximoLinkedList(&lista_definicoes);
      if(d->tipo_uf == STORE_UF) return 1;
      return 0;
    }
  }
  printf("\nInstrução não definida no arquivo def_file.txt\n");
  resetProximoLinkedList(&lista_definicoes);
  return NULL;
}


//TODO:
int isInconditionalJump(Instrucao * i){
  /*Tipo J ou tipo R com opcodes e func específicos*/
  return 1;
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
  printf("\n\nQuantidades de Estações de Reserva:\nADD:\t%d\nMUL:\t%d\nLOAD:\t%d\nSTORE:\t%d\nTOTAL:\t%d\n\n", QUANTIDADE_ESTACOES_RESERVA_ADD, QUANTIDADE_ESTACOES_RESERVA_MUL, QUANTIDADE_ESTACOES_RESERVA_LOAD, QUANTIDADE_ESTACOES_RESERVA_STORE, QUANTIDADE_ESTACOES_RESERVA);
}

void show_instruction_details(char * mnemonic){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(!strcasecmp(d->mnemonic, mnemonic)) break;
  }
  resetProximoLinkedList(&lista_definicoes);
  if(d == NULL){
    printf("\nInstrução não definida no arquivo def_file.txt\n");
    return;
  }
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
