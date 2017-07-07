#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <string.h>

typedef int TIPOCHAVE;

typedef struct estrutura{
    TIPOCHAVE ponteiro_estr;
    struct estrutura *prox;
}NO;

typedef struct{
    NO* inicio;
    NO* atual;
}LinkedList;

//int removeLinkedList(LinkedList *list, TIPOCHAVE ch);
//NO* buscaLinkedList(LinkedList list, TIPOCHAVE ch, NO** ant);
void inicializarLista(LinkedList *list);
int getSizeofLinkedList(LinkedList list);
void resetProximoLinkedList(LinkedList * lista);
TIPOCHAVE getProximoLinkedList(LinkedList * lista);
int destroyLinkedList(LinkedList *list);
void insertLinkedList(LinkedList *list, TIPOCHAVE ch);

#endif
