#include "include/LinkedList.h"

void inicializar(LinkedList *list){
    list->inicio = NULL;
    list->atual = list->inicio;
}

NO* buscar(LinkedList list, TIPOCHAVE ch, NO** ant) {
    NO* noAtual = list.inicio;
    *ant = NULL;
    while(noAtual){
            if(strcmp(noAtual->ponteiro_estr, ch) >= 0){
                break;
            }
            *ant = noAtual;
            noAtual = noAtual->prox;
    }
    if(noAtual){
            if(strcmp(noAtual->ponteiro_estr, ch) == 0){
                return noAtual;
            }
    }
    return NULL;
}

int getSizeofLinkedList(LinkedList list){
    int tam = 0;
    NO* noAtual = list.inicio;
    while(noAtual){
        tam++;
        noAtual = noAtual->prox;
    }
    return tam;
}

void reset_contador(LinkedList * lista){
  lista->atual = lista->inicio;
}

TIPOCHAVE get_proximo(LinkedList * lista){
  TIPOCHAVE retorno = NULL;
  if(lista->atual != NULL){
     retorno = lista->atual->ponteiro_estr;
     lista->atual = lista->atual->prox;
  }
  return retorno;
}

int remover(LinkedList *list, TIPOCHAVE ch){
    NO* ant; NO* noAtual = buscar(*list, ch, &ant);
    if(!noAtual) return 0;
    if(!ant){
        list->inicio = noAtual->prox;
    }else{
        ant->prox = noAtual->prox;
    }
    noAtual->prox = NULL;
    free(noAtual);
    return 1;
}

void inserir(LinkedList *list, TIPOCHAVE ch){
  NO * new_node;
  new_node = malloc(sizeof(NO));

  new_node->ponteiro_estr = ch;
  new_node->prox = list->inicio;

  list->inicio = new_node;
  reset(list);
}


/*
void insertLinkedList(LinkedList *list, TIPOCHAVE ch){
    NO* ant;
    NO* novoNo = buscaLinkedList(*list, ch, &ant);
    if(novoNo) return;
    novoNo = (NO*) malloc(sizeof(NO));
    novoNo->ponteiro_estr = ch;
    //Inserção no início
    if(!ant){
        novoNo->prox = list->inicio;
        list->inicio = novoNo;
    }else{ //Caso geral
        novoNo->prox = ant->prox;
        ant->prox = novoNo;
    }
    resetProximoLinkedList(list);
}*/
