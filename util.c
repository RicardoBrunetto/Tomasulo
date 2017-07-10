#include "util.h"

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

/*Função que retorna verdadeiro (1) se a instrução puder ser processada por uma UF de Load*/
int isLoad(int opcode){
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL){
    if(d->opcode == opcode){
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
