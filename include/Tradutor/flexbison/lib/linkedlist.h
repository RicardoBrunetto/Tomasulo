#include <stdlib.h>
#include <string.h>

typedef char* TIPOCHAVE;

typedef struct estrutura{
    int offset;
    TIPOCHAVE label;
    struct estrutura *prox;
}NO;

typedef struct{
    NO* inicio;
}LinkedList;

void inicializarLista(LinkedList *list){
    list->inicio = NULL;
    //printf("\nLista de Labels inicializada!\n");
}

int inserirPosicao(LinkedList *list, int pos, TIPOCHAVE ch, int offset){
    int i = 1;

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->label = ch;
    novo->offset = offset;

    if(pos==0){
        novo->prox = list->inicio;
        list->inicio = novo;
        return 1;
    }

    NO* noAtual = list->inicio;
    NO* ant = list->inicio;

    while(noAtual){
        ant = noAtual;
        noAtual = noAtual->prox;
        if(i==pos){
            novo->prox = noAtual;
            ant->prox = novo;
            return 1;
        }
        i++;
    }
    //printf("Falha!");
    return 0;
}

NO* buscaLinkedList(LinkedList list, TIPOCHAVE ch, NO** ant) {
    NO* noAtual = list.inicio;
    *ant = NULL;
    while(noAtual){
            if(strcmp(noAtual->label, ch) >= 0){
                break;
            }
            *ant = noAtual;
            noAtual = noAtual->prox;
    }
    if(noAtual){
            if(strcmp(noAtual->label, ch) == 0){
                return noAtual;
            }
    }
    return NULL;
}

void exibirLinkedList(LinkedList list){
    NO* noAtual = list.inicio;
    printf("\n\tINICIO");
    while(noAtual){
        printf("\n[Chave: %s\t->offset: %i]", noAtual->label, noAtual->offset);
        noAtual = noAtual->prox;
        if(!noAtual){
            printf("\n\tFIM\n");
        }
    }
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

NO* getFirstLinkedList(LinkedList list){
    if(!list.inicio){
        //printf("\nLista Vazia!\n");
    }else{
        //printf("\nPRIMEIRO ELEMENTO:\n\tChave: %s\n\toffset: %i\n", list.inicio->label, list.inicio->offset);
    }
    return list.inicio;
}

NO* getLastLinkedList(LinkedList list){
    NO* noAtual = list.inicio;
    if(!noAtual){
        //printf("\nLista Vazia!\n");
    }

    while(noAtual){
        if(!noAtual->prox){
            return noAtual;
        }
        noAtual = noAtual->prox;
    }
}

NO* getnLinkedList(LinkedList list, int order){
    int count = 1;
    NO* noAtual = list.inicio;

    while(noAtual){
        if(count == order){
            return noAtual;
        }
        noAtual = noAtual->prox;
        count++;
    }

    //printf("\nElemento inexistente!\n");
    return NULL;
}

int removeLinkedList(LinkedList *list, TIPOCHAVE ch){
    NO* ant; NO* noAtual = buscaLinkedList(*list, ch, &ant);

    if(!noAtual){
        return 0;
    }

    if(!ant){
        list->inicio = noAtual->prox;
    }else{
        ant->prox = noAtual->prox;
    }
    noAtual->prox = NULL;
    free(noAtual);
    return 1;
}

int destroyLinkedList(LinkedList *list){
    NO* noAtual = list->inicio; NO* aux;
    while(noAtual){
        aux = noAtual->prox;
        noAtual->prox = NULL;
        //printf("\nElemento destruido:\n\tChave: %s\n\toffset: %i\n", noAtual->label, noAtual->offset);
        free(noAtual);
        noAtual = aux;
    }
    list->inicio = NULL;
    //printf("\n\tDynamic Ordened Linked List Destruida!\n");
}

int getOffset(LinkedList list, TIPOCHAVE ch){
    NO * ant, *ret;
    //printf("\n\nch: %s", ch);
    ret = buscaLinkedList(list, ch, &ant);
    if(ret != NULL){
      //printf("\nval: %i\n", ret->offset);
      return (ret->offset);
    }else{
      //printf("\nErro.");
      return 0;
    }
}

void insertLinkedList(LinkedList *list, TIPOCHAVE ch, int offset){
    NO* ant;
    NO* novoNo = buscaLinkedList(*list, ch, &ant);

    if(novoNo){
        //printf("\nChave ja existente!\n");
        return;
    }
    novoNo = (NO*) malloc(sizeof(NO));
    novoNo->label = ch;
    novoNo->offset = offset;

        //Inserção no início
        if(!ant){
            novoNo->prox = list->inicio;
            list->inicio = novoNo;
        }else{ //Caso geral
            novoNo->prox = ant->prox;
            ant->prox = novoNo;
        }
}
