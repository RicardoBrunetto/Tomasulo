#include "include/DQueue.h"

void inicializar_fila(Fila *f){
  f->cabeca = NULL;
  f->cauda = NULL;
}

void inserir_fila(Fila *f, TIPO_INFO *item){
    //printf("[FILA]\tInserting item : %d\n", item);
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
    if (f->cabeca == NULL) return NULL;
    else return f->cabeca->data;
}


void mostrar_fila(Fila *f){
    struct node *temp;
    temp = f->cabeca;
    printf("Fila (%d)\n", f);
    while (temp != NULL){
        printf("\t->[Ponteiro] %d\n", temp->data);
        temp = temp->next;
    }
    printf("Fim\n");
}


TIPO_INFO * remover_fila( Fila * s ){
  struct node * h = NULL;
  struct node * p = NULL;
  TIPO_INFO * t;
  if( NULL == s->cabeca && NULL == s->cauda ) return NULL;

  h = s->cabeca;
  p = h->next;
  t = h->data;
  free(h);
  s->cabeca = p;
  if( NULL == s->cabeca )  s->cauda = s->cabeca;
  return t;
}


/*
TIPO_INFO * remover_fila(Fila *f){
  TIPO_INFO * ret;
  struct node *temp;
  temp = f->cabeca;
  if (f->cabeca == NULL){
      f->cabeca = f->cauda = NULL;
      return NULL;
  }else{
      ret = f->cabeca->data;
      f->cabeca = f->cabeca->next;
      free(temp);
      return ret;
  }
}
TIPO_INFO * remover_fila(Fila *f){
    if (f->cabeca == NULL) return NULL;
    else{
      struct node *temp;
      temp = f->cabeca;
      f->cabeca = f->cabeca->next;
      return temp->data;
    }
}*/

void limpar_fila(Fila *f){
  struct node *temp;
  temp = f->cabeca;
  while (temp != NULL){
      free(temp);
      temp = temp->next;
  }
  inicializar_fila(f);
}
