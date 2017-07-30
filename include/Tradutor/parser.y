%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/assembler.util.h"
#include "../definitions.h"

LinkedList lista;

int address = 0, secondPass = 0, dados_offset = START_ADDRESS_DATA, data_Bytes = 0;
char * error_msg = "Instrução não definida\n";

FILE* yyin;
char * mnemonico, *start_label;
int state, hasinserted = 0;

typedef struct{
  int numeros[10];
  int qtdNum;
}NumStruct;

NumStruct nstruct;

%}

%union{
  struct R_type{
    int opcode, rd, rs, rt, func, shift;
  }instruction_R;
  struct J_type{
    int opcode, target;
  }instruction_J;
  struct I_type{
    int opcode, rs, rt, imm;
  }instruction_I;
  int valor;
  char *str;
}

/* declare tokens */
%token ABRE_PAR
%token FECHA_PAR
%token <valor> NUMBER
%token ECOM
%token <str> ADDRESS IDENTIFICADOR
%token <valor> REG_S REG_AT REG_T REG_A REG_V REG_K REG_GP REG_SP REG_FP REG_R REG_ZERO
%token <instruction_R> ADD ADDU AND CLO CLZ DIV DIVU MULT MULTU MUL MADD MOVN MADDU MSUB MSUBU NOR OR SLL SLLV SRA SRAV SRL SRLV SUB SUBU XOR SLT SLTU TEQ TNE TGE TGEU TLT TLTU MFHI MFLO MTHI MTLO MOVZ MOVF MOVT ERET SYSCALL BREAK NOP
%token <instruction_I> ADDI ADDIU ANDI ORI XORI LUI SLTI SLTIU BEQ BGEZ BGEZAL BGTZ BLEZ BLTZAL BLTZ BNE TEQI TNEQ TGEI TGEIU TLTI TLTIU LB LBU LH LHU LW LWL LWR LL SB SH SW SWR SWL SC
%token <instruction_J> J JAL JALR JR
%token DATA TEXT SECTION DPTS INT EOL COMMA GLOBL
%token <str> HEX_VAL

%type <valor> nro
%type <valor> nrorlabel
%type <valor> reg
%type <instruction_R> instrucao_R
%type <instruction_I> instrucao_I
%type <instruction_J> instrucao_J

%%
all: general
   | assembly

general: spec eol definitions {show_config();}

spec: ECOM IDENTIFICADOR DPTS NUMBER eol ECOM IDENTIFICADOR DPTS NUMBER eol ECOM IDENTIFICADOR DPTS NUMBER eol ECOM IDENTIFICADOR DPTS NUMBER{
        QUANTIDADE_ESTACOES_RESERVA_ADD = $4;
        QUANTIDADE_ESTACOES_RESERVA_MUL = $9;
        QUANTIDADE_ESTACOES_RESERVA_LOAD = $14;
        QUANTIDADE_ESTACOES_RESERVA_STORE = $19;
        QUANTIDADE_ESTACOES_RESERVA = $4 + $9 + $14 + $19;
      }

definitions: |
            definitions ABRE_PAR IDENTIFICADOR DPTS NUMBER COMMA NUMBER COMMA IDENTIFICADOR COMMA IDENTIFICADOR COMMA NUMBER FECHA_PAR eol {
             Def * d = (Def *)malloc(sizeof(Def));
             d->mnemonic = $3;
             d->opcode = $5;
             d->ciclos = $7;
             d->formato = get_formato_based($9);
             d->tipo_uf = get_uf_based($11);
             d->cessa_emissao = $13;
             d->function = FLAG_VAZIO; /*Não possuem Function*/
             d->abstract_opcode = $5; /*Não possuem Abstract Opcode*/
             insertLinkedList(&lista_definicoes, d);
           } |
           definitions ABRE_PAR IDENTIFICADOR DPTS NUMBER COMMA NUMBER COMMA IDENTIFICADOR COMMA IDENTIFICADOR COMMA NUMBER COMMA NUMBER COMMA NUMBER FECHA_PAR eol {
             Def * d = (Def *)malloc(sizeof(Def));
             d->mnemonic = $3;
             d->opcode = $5;
             d->ciclos = $7;
             d->formato = get_formato_based($9);
             d->tipo_uf = get_uf_based($11);
             d->function = $13;
             d->abstract_opcode = $15;
             d->cessa_emissao = $17;
             insertLinkedList(&lista_definicoes, d);
           }

eol:
  | eol EOL


assembly: data_section eol text_section

data_section:
            | DATA eol variaveis {if(secondPass == 1) insertNop(data_Bytes);}

text_section:
            | TEXT eol global_def eol lista_instrucoes

global_def:
          | GLOBL IDENTIFICADOR {start_label = strdup($2);}

variaveis:
         | variaveis variavel eol

variavel: IDENTIFICADOR DPTS INT numeros eol {if(secondPass == 0){
                                                SLabel * var = (SLabel *)malloc(sizeof(SLabel));
                                                var->lbl_identificador = $1;
                                                var->lbl_offset = dados_offset;
                                                insertLinkedList(&lista, var);
                                                dados_offset += (nstruct.qtdNum * WORD_SIZE);
                                                data_Bytes++;
                                              }else{
                                                setData(getOffset(&lista, $1), nstruct.numeros, nstruct.qtdNum);
                                              } nstruct.qtdNum = 0;}

numeros: nro {nstruct.numeros[nstruct.qtdNum] = $1; nstruct.qtdNum = nstruct.qtdNum +1;}
       | nro comma numeros {nstruct.numeros[nstruct.qtdNum] = $1; nstruct.qtdNum = nstruct.qtdNum +1;}

nro: NUMBER | HEX_VAL {$$ = hex_to_dec($1);}

nrorlabel: NUMBER | HEX_VAL {$$ = hex_to_dec($1);} | IDENTIFICADOR {$$ = getOffset(&lista, $1);}

comma:
     | COMMA

lista_instrucoes:
                | lista_instrucoes label_decl instrucao eol

label_decl:
          | IDENTIFICADOR DPTS eol {if(secondPass == 0){
                                      SLabel * label_found = (SLabel *)malloc(sizeof(SLabel));
                                      label_found->lbl_identificador = $1;
                                      label_found->lbl_offset = address;
                                      insertLinkedList(&lista, label_found);
                                    }}

instrucao: instrucao_R {if(secondPass == 1){ if(!hasinserted)setmain(); setInstruction_R($1.opcode, $1.rs, $1.rt, $1.rd, $1.shift, $1.func, address+=WORD_SIZE); }else{ address += WORD_SIZE; }}
         | instrucao_I {if(secondPass == 1){ if(!hasinserted)setmain(); setInstruction_I($1.opcode, $1.rs, $1.rt, $1.imm, address+=WORD_SIZE); }else{ address += WORD_SIZE; }}
         | instrucao_J {if(secondPass == 1){ if(!hasinserted)setmain(); setInstruction_J($1.opcode, $1.target, address+=WORD_SIZE); }else{ address += WORD_SIZE; }}

instrucao_R: ADD reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | ADDU reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | AND reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | CLZ reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | DIV reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = $2; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | DIVU reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = $2; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | MULT reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = $2; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | MULTU reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = $2; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | MUL reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | MSUB reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = $2; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | MSUBU reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = $2; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | NOR reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | OR reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | SLL reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = 0; $$.rt = $4; $$.shift = $6; $$.func = d->function;}}
           | SLLV reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $6; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | SRA reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = 0; $$.rt = $4; $$.shift = $6; $$.func = d->function;}}
           | SRAV reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $6; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | SRL reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = 0; $$.rt = $4; $$.shift = $6; $$.func = d->function;}}
           | SRLV reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $6; $$.rt = $4; $$.shift = 0; $$.func = d->function;}}
           | SUB reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | SUBU reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | XOR reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | SLT reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | SLTU reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | JALR reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | JALR reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 31; $$.rs = $2; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | JR reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = $2; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | MFHI reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = 0; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | MFLO reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = 0; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | MTHI reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = REG_HI; $$.rs = $2; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | MTLO reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = REG_LO; $$.rs = $2; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}
           | MOVN reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | MOVZ reg comma reg comma reg {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = 0; $$.func = d->function;}}
           | SYSCALL {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = 2/*$v0*/; $$.rt = 4/*$a0*/; $$.shift = 0; $$.func = d->function;}}
           | NOP {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rd = 0; $$.rs = 0; $$.rt = 0; $$.shift = 0; $$.func = d->function;}}


instrucao_J: J nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.target = $2;}}
           | JAL nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.target = $2;}}

instrucao_I: ADDI reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $4; $$.imm = $6;}}
           | ADDIU reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $4; $$.imm = $6;}}
           | ANDI reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $4; $$.imm = $6;}}
           | ORI reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $4; $$.imm = $6;}}
           | XORI reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $4; $$.imm = $6;}}
           | LUI reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | SLTI reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $4; $$.imm = $6;}}
           | SLTIU reg comma reg comma nro {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $4; $$.imm = $6;}}
           | BEQ reg comma reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $4; $$.rs = $2; $$.imm = $6;}}
           | BGEZ reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = d->function; $$.rs = $2; $$.imm = $4;}}
           | BGEZAL reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = d->function; $$.rs = $2; $$.imm = $4;}}
           | BGTZ reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = 0; $$.rs = $2; $$.imm = $4;}}
           | BLEZ reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = 0; $$.rs = $2; $$.imm = $4;}}
           | BLTZAL reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = d->function; $$.rs = $2; $$.imm = $4;}}
           | BLTZ reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = d->function; $$.rs = $2; $$.imm = $4;}}
           | BNE reg comma reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $4; $$.rs = $2; $$.imm = $6;}}
           | LB reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | LB reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | LBU reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | LBU reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | LH reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | LH reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | LHU reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | LHU reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | LW reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | LW reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | LWL reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | LWL reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | LWR reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | LWR reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | SB reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | SB reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | SH reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | SH reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | SW reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | SW reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | SWL reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | SWL reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}
           | SWR reg comma nrorlabel ABRE_PAR reg FECHA_PAR {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = $6; $$.imm = $4;}}
           | SWR reg comma nrorlabel {if(secondPass == 1){ Def * d = get_def_mnemonico(mnemonico); if(d==NULL) yyerror(error_msg); $$.opcode = d->opcode; $$.rt = $2; $$.rs = 0; $$.imm = $4;}}

reg: REG_S { $$ = get_indice_reg(0, $1); }
   | REG_AT { $$ = 1; }
   | REG_T { $$ = get_indice_reg(1, $1); }
   | REG_A { $$ = get_indice_reg(2, $1); }
   | REG_V { $$ = $1 == 0 ? 2 : 3; }
   | REG_K { $$ = $1 == 0 ? 26 : 27; }
   | REG_GP {$$ = 28;}
   | REG_SP {$$ = 29;}
   | REG_FP {$$ = 30;}
   | REG_R {$$ =  31;}
   | REG_ZERO {$$ = 0;}
%%

void setmain(){
  Def * d = get_def_mnemonico("j");
  if(d==NULL) yyerror(error_msg);
  int opcode = d->opcode; int target = getOffset(&lista, start_label);
  if(target != 0)
    setInstruction_J(opcode, target, address+=WORD_SIZE);
  hasinserted = 1;
}

void call_tradutor(FILE *f){
  state = FLAG_ASSEMBLER;
  nstruct.qtdNum = 0;
  inicializarLista(&lista);
  secondPass = 0;
  if(f == NULL){
    yyerror("Arquivo invalido para o tradutor!");
    return;
  }

  yyrestart(f);
  yyparse();

  print_lista_labels(&lista);

  secondPass = 1;
  system("mkdir -p output/");
  output = fopen("output/output", "w+");

  rewind(f);
  yyparse();


  fclose(output);
}

int get_uf_based(char * uf){
  if(!strcmp(uf, "ADD_UF"))
      return ADD_UF;
  else if(!strcmp(uf, "MUL_UF"))
      return MUL_UF;
  else if(!strcmp(uf, "LOAD_UF"))
      return LOAD_UF;
  else if(!strcmp(uf, "STORE_UF"))
      return STORE_UF;
  else
      yyerror("TIPO INVÁLIDO DE UNIDADE FUNCIONAL");
}

int get_formato_based(char * formato){
  if(!strcmp(formato, "TYPE_R"))
      return TYPE_R;
  else if(!strcmp(formato, "TYPE_J"))
      return TYPE_J;
  else if(!strcmp(formato, "TYPE_I"))
      return TYPE_I;
  else
      yyerror("TIPO INVÁLIDO DE INSTRUÇÃO");
}

int run_definitions(){
  state = FLAG_DEFINER;
  inicializarLista(&lista_definicoes);
  yyin = fopen("include/def_file.txt", "r");
  do {
		yyparse();
	} while (!feof(yyin));
  fclose(yyin);
}

int yyerror(char *s) {
  fprintf(stderr, "\nerror: %s\n", s);
  exit(0);
}
