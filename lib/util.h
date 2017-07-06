#include <stdio.h>
#include <string.h>

#ifndef PROC_UTIL_H
#define PROC_UTIL_H

/*Definições de Flags para controle das instruções*/
#define TYPE_R 1
#define TYPE_J 2
#define TYPE_I 3

/*Union de Instruções.
 Serve para representar os três tipos de instruções simultaneamente
 O tipo de instrução está na variável type*/
typedef struct{
   enum tipos_validos { IS_R, IS_J, IS_I } type;

   union union_instr{
     struct R_t{
       int cycles;
       int opcode, rd, rs, rt, func, shift;
     }instruction_R;
     struct J_t{
       int cycles;
       int opcode, target;
     }instruction_J;
     struct I_t{
       int cycles;
       int opcode, rs, rt, imm;
     }instruction_I;
   }instruction;
}Instrucao;

int getTipo_instrucao(int opcode);
Instrucao * decodificar(int instr);
int isInconditionalJump(Instrucao * i);
int tipo_compativel(int tipo_instrucao, int tipo_uf);
#endif
