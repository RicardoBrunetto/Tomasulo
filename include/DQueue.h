#include <stdio.h>
#include <stdlib.h>

#ifndef DQUEUE_H
#define DQUEUE_H

/*Apelido para o tipo de informação que a Fila armazenará*/
typedef int TIPO_INFO;

/*Definições de enum para controle das instruções*/
typedef enum { TYPE_R, TYPE_J, TYPE_I } Tipo_Instrucao;
typedef enum { ADD_UF, MUL_UF, LOAD_UF, STORE_UF } Tipo_ER_UF;

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

/*Union de Instruções.*/
typedef struct{
   Tipo_Instrucao type;
   int opcode;

   union union_instr{
     struct R_t{
       int rd, rs, rt, func, shift;
     } instruction_R;
     struct J_t{
       int target;
     } instruction_J;
     struct I_t{
       int rs, rt, imm;
     } instruction_I;
   }instruction;
}Instrucao;

/*Protótipos*/
void inicializar_fila(Fila *);
void mostrar_fila(Fila *);
void inserir_fila(Fila *, TIPO_INFO *);
TIPO_INFO * remover_fila(Fila *);
TIPO_INFO * get_topo_fila(Fila *f);

#endif
