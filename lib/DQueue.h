#include <stdio.h>
#include <stdlib.h>

#ifndef DQUEUE_H
#define DQUEUE_H

/*Apelido para o tipo de informação que a Fila armazenará*/
typedef int TIPO_INFO;

/*Declaração da Estrutura de Fila*/
struct node{
    TIPO_INFO * data;
    struct node *next;
};
typedef struct queue{
  /*Ponteiros que a estrutura de Fila precisará*/
  struct node *cabeca;
  struct node *cauda;
}Fila;


/*Protótipos*/
void inicializar_fila(Fila *);
void mostrar_fila(Fila *);
void inserir_fila(Fila *, TIPO_INFO *);
TIPO_INFO * remover_fila(Fila *);
TIPO_INFO * get_topo_fila(Fila *f);

#endif
