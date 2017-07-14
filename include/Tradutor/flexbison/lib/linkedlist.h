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

void inicializarLista(LinkedList *list);

int inserirPosicao(LinkedList *list, int pos, TIPOCHAVE ch, int offset);

NO* buscaLinkedList(LinkedList list, TIPOCHAVE ch, NO** ant);

void exibirLinkedList(LinkedList list);

int getSizeofLinkedList(LinkedList list);

NO* getFirstLinkedList(LinkedList list);

NO* getLastLinkedList(LinkedList list);

NO* getnLinkedList(LinkedList list, int order);

int removeLinkedList(LinkedList *list, TIPOCHAVE ch);

int destroyLinkedList(LinkedList *list);

int getOffset(LinkedList list, TIPOCHAVE ch);

void insertLinkedList(LinkedList *list, TIPOCHAVE ch, int offset);
