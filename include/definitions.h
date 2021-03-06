#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "DQueue.h"
#include "LinkedList.h"

#define WORD_SIZE 4 /*Tamanho de uma palavra (em bytes)*/
//#define START_ADDRESS_DATA 100
#define START_ADDRESS_DATA 0x4000000
#define DATA_AMOUNT    400

#define FLAG_VERBOSE    1
#define FLAG_NORMAL     0

#define FLAG_EXIT       17
#define FLAG_READY      -3
#define FLAG_BUSY       -2
#define FLAG_VAZIO      -1
#define FLAG_READ        0
#define FLAG_WRITE       1
#define FLAG_DISPONIVEL -1
/*Fixa as posições dos registradores RA, HI e LO*/
#define REG_PG 28 /*GP*/
#define REG_PS 29 /*SP*/
#define REG_RA 31
#define REG_HI 32
#define REG_LO 33


/*Definições das quantidades de Estações de Reserva*/
extern int QUANTIDADE_ESTACOES_RESERVA_ADD, QUANTIDADE_ESTACOES_RESERVA_MUL, QUANTIDADE_ESTACOES_RESERVA_LOAD, QUANTIDADE_ESTACOES_RESERVA_STORE;
extern int QUANTIDADE_ESTACOES_RESERVA;

/*Estrutura de definição*/
typedef struct{
  char * mnemonic;
  int opcode, function, ciclos, abstract_opcode, cessa_emissao;
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
    int dado, endereco, controle;
}Dado_Barramento;
typedef struct{
    int status;
    Fila * fila_barramento;
}Barramento;

/*Barramento RAM-Cache*/
struct decomposicao {
    unsigned long long int b0_31   : 32;
    unsigned long long int b32_63  : 32;
    unsigned long long int b64_95  : 32;
    unsigned long long int b96_127 : 32;
};
typedef union{
    struct decomposicao bits;
    unsigned long long int full_value;
}Dado_Barramento_128;
typedef struct{
  Dado_Barramento_128 * dado;
  int endereco, controle, status;
}Barramento128bits;

/*Estrutura de Registrador*/
typedef struct{
  int Qi, valor;
}Registrador;

/*Lista de definições*/
extern LinkedList lista_definicoes;

int EMISSAO_CESSADA;
int BUSCA_DECOD_CESSADA;

/*Fila de Instruções a serem processadas*/
Fila fila_Instrucoes;
int MODULE;

#endif
