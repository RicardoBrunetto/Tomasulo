#ifndef PROC_UTIL_H
#define PROC_UTIL_H

#include <stdio.h>
#include <string.h>
#include "definitions.h"
#include "DQueue.h"

int get_ciclos(int opcode);
int getTipo_instrucao(int opcode);
int is_uf_compativel(int opcode, int tipo_uf);
int get_abstract_opcode(int opcode, int funct);
int isLoad(int opcode);
int isStore(int opcode);
int isInconditionalJump(Instrucao * i);
void show_config();
void show_instruction_details(char * mnemonic);
int get_def_mnemonico(char * mnemonico);
int get_def_absopcode(int absopcode);
int is_cessar_emissao(int opcode);
int is_escrever_hi_lo(int opcode);
int is_cessar_busca_decode(Instrucao * i);
int is_branch(int absopcode);
int is_writter_branch(int absopcode);
int isLoad(int absopcode);
int isStore(int absopcode);
int is_rt_destino(int absopcode);
int is_rt_operando(int absopcode);
int is_conditionalMove(int absopcode);
int filtrar_dado(int absopcode, int dado);
void limpar_fila_instrucoes();

#endif
