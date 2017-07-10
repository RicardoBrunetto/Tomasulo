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
  printf("\nInstrução não definida no arquivo def_file.txt\n");
  resetProximoLinkedList(&lista_definicoes);
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
}

//TODO:
int isInconditionalJump(Instrucao * i){
  return 1;
}
