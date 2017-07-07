#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "LinkedList.h"

/*Estrutura de definição*/
typedef struct{
  char * mnemonic;
  int opcode, ciclos;
  Tipo_Instrucao formato;
  Tipo_ER_UF tipo_uf;
}Def;

/*Lista de definições*/
LinkedList lista_definicoes;

/*Definições de enum para controle das instruções*/
typedef enum { TYPE_R, TYPE_J, TYPE_I } Tipo_Instrucao;
typedef enum { ADD_UF, MUL_UF, LOAD_UF, STORE_UF } Tipo_ER_UF;
/*Union de Instruções.
 Serve para representar os três tipos de instruções simultaneamente
 O tipo de instrução está na variável type*/
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

#endif
