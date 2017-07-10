#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "LinkedList.h"

/*Definições de enum para controle das instruções*/
typedef enum { TYPE_R, TYPE_J, TYPE_I } Tipo_Instrucao;
typedef enum { ADD_UF, MUL_UF, LOAD_UF, STORE_UF } Tipo_ER_UF;
int QUANTIDADE_ESTACOES_RESERVA_ADD, QUANTIDADE_ESTACOES_RESERVA_MUL, QUANTIDADE_ESTACOES_RESERVA_LOAD, QUANTIDADE_ESTACOES_RESERVA_STORE;
int QUANTIDADE_ESTACOES_RESERVA;

/*Estrutura de definição*/
typedef struct{
  char * mnemonic;
  int opcode, ciclos;
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
  int BusyBit, Qj, Vj, Qk, Vk, a, Op;
  UnidadeFuncional uf;
}EstacaoReserva;

/*Estrutura de Barramento*/
typedef struct{
    int dado, endereco;
}Barramento;

/*Estrutura de Registrador*/
typedef struct{
  int Qi, valor;
}Registrador;

/*Union de Instruções.*/
typedef struct{
   Tipo_Instrucao type;

   union union_instr{
     struct R_t{
       int opcode, rd, rs, rt, func, shift;
     }instruction_R;
     struct J_t{
       int opcode, target;
     }instruction_J;
     struct I_t{
       int opcode, rs, rt, imm;
     }instruction_I;
   }instruction;
}Instrucao;

/*Lista de definições*/
LinkedList lista_definicoes;

#endif
