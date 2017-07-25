#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "DQueue.h"
#include "LinkedList.h"

#define WORD_SIZE 4 /*Tamanho de uma palavra (em bytes)*/
#define START_ADDRESS_DATA 100
//#define START_ADDRESS_DATA 0x4000000
#define DATA_AMOUNT    400

#define FLAG_VAZIO -1
#define FLAG_READ   0
#define FLAG_WRITE  1
#define FLAG_BUSY   2
#define FLAG_READY  3

/*Definições de enum para controle das instruções*/
typedef enum { TYPE_R, TYPE_J, TYPE_I } Tipo_Instrucao;
typedef enum { ADD_UF, MUL_UF, LOAD_UF, STORE_UF } Tipo_ER_UF;

/*Definições das quantidades de Estações de Reserva*/
extern int QUANTIDADE_ESTACOES_RESERVA_ADD, QUANTIDADE_ESTACOES_RESERVA_MUL, QUANTIDADE_ESTACOES_RESERVA_LOAD, QUANTIDADE_ESTACOES_RESERVA_STORE;
extern int QUANTIDADE_ESTACOES_RESERVA;

/*Estrutura de definição*/
typedef struct{
  char * mnemonic;
  int opcode, function, ciclos, abstract_opcode;
  Tipo_Instrucao formato;
  Tipo_ER_UF tipo_uf;
}Def;

/*Estruturas da Unidade Funcional*/
typedef struct{
  Tipo_ER_UF type; //Tipo de Unidade Funcional
  int ALUOutput; //Buffer que segura a saída da Unidade Funcional
}UnidadeFuncional;

/*Estrutura da Estação de Reserva*/
typedef struct{
  int BusyBit, Qj, Vj, Qk, Vk, A, Op;
  UnidadeFuncional uf;
}EstacaoReserva;

/*Estrutura de Barramento*/
typedef struct{
    int dados, endereco, controle;
    Fila * fila_barramento;
}Barramento;

/*Estrutura de Registrador*/
typedef struct{
  int Qi, valor;
}Registrador;

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

/*Lista de definições*/
extern LinkedList lista_definicoes;


#endif
