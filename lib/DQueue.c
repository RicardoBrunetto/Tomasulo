#include "DQueue.h"

void inicializar_fila(Fila *f){
  f->cabeca = NULL;
  f->cauda = NULL;
}

void inserir_fila(Fila *f, TIPO_INFO *item){
    struct node *nptr = (struct node *) malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = NULL;
    if (f->cauda == NULL){
        f->cabeca = nptr;
        f->cauda = nptr;
    }else{
        f->cauda->next = nptr;
        f->cauda = f->cauda->next;
    }
}

/*Retorna o topo da fila sem precisar removê-la dali*/
TIPO_INFO * get_topo_fila(Fila *f){
    if (f->cabeca == NULL)
      //TODO: Adicionar o que fazer quando a fila estiver Vazia
      return NULL;
    else{
      return f->cabeca->data;
    }
}


void mostrar_fila(Fila *f){
    struct node *temp;
    temp = f->cabeca;
    printf("\n");
    while (temp != NULL){
        printf("[Ponteiro] %d\t", temp->data);
        temp = temp->next;
    }
}

TIPO_INFO * remover_fila(Fila *f){
    if (f->cabeca == NULL)
      //TODO: Adicionar o que fazer quando a fila estiver Vazia
      return NULL;
    else{
      struct node *temp;
      temp = f->cabeca;
      f->cabeca = f->cabeca->next;
      return temp->data;
    }
}
