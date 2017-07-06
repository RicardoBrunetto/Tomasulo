%{
#define START_ADDRESS_DATA 0x10000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/util.c"
#include "lib/linkedlist.h"

LinkedList lista;

int address = 0, passada = 0, dados_offset = START_ADDRESS_DATA;
char * string;
%}

%union{
  struct R_type{
    char *opcode, *rd, *rs, *rt, *func, *shift;
  }instruction_R;
  struct J_type{
    char *opcode, *target;
  }instruction_J;
  struct I_type{
    char *opcode, *rs, *rt, *imm;
  }instruction_I;
  struct val{
    char ** numeros;
    int qtdNum;
  }num;
  int valor;
  char *str;
}

/* declare tokens */
%token <str> NUMBER
%token <str> ADDRESS IDENTIFICADOR
%token <str> REG_S REG_AT REG_T REG_A REG_V REG_K REG_GP REG_SP REG_FP REG_RA REG_ZERO
%token <instruction_R> ADD ADDU AND CLO CLZ DIV DIVU MULT MULTU MUL MADD MADDU MSUB MSUBU NOR OR SLL SLLV SRA SRAV SRL SRLV SUB SUBU XOR SLT SLTU TEQ TNE TGE TGEU TLT TLTU MFHI MFLO MTHI MTLO MOVZ MOVF MOVT ERET SYSCALL BREAK NOP
%token <instruction_I> ADDI ADDIU ANDI ORI XORI LUI SLTI SLTIU BEQ BGEZ BGEZAL BGTZ BLEZ BLTZAL BLTZ BNE TEQI TNEQ TGEI TGEIU TLTI TLTIU LB LBU LH LHU LW LWL LWR LL SB SH SW SWR SWL SC
%token <instruction_J> J JAL JALR JR
%token DATA TEXT SECTION DPTS INT EOL COMMA

%type <str> reg
%type <instruction_R> instrucao_R
%type <instruction_I> instrucao_I
%type <instruction_J> instrucao_J
%type <num> numeros

%%
assembly: data_section eol text_section

data_section:
            | DATA eol variaveis

text_section:
            | TEXT eol lista_instrucoes {}

variaveis:
         | variaveis variavel eol

variavel: IDENTIFICADOR DPTS INT numeros eol {if(passada == 0) insertLinkedList(&lista, $1, dados_offset++); else setData(getOffset(lista, $1), $4.numeros, $4.qtdNum);}

numeros: NUMBER {$$.numeros[$$.qtdNum] = strdup($1); $$.qtdNum = $$.qtdNum +1;}
       | NUMBER comma numeros {$$.numeros[$$.qtdNum] = strdup($1); $$.qtdNum = $$.qtdNum +1;}

comma:
     | COMMA

lista_instrucoes:
                | lista_instrucoes label_decl instrucao eol

label_decl:
          | IDENTIFICADOR DPTS eol {if(passada == 0) insertLinkedList(&lista, $1, address);}

eol:
   | eol EOL

instrucao: instrucao_R {if(passada == 1) setInstruction_R($1.opcode, $1.rs, $1.rt, $1.rd, $1.shift, $1.func); address++;}
         | instrucao_I {if(passada == 1) setInstruction_I($1.opcode, $1.rs, $1.rt, $1.imm); address++;}
         | instrucao_J {if(passada == 1) setInstruction_J($1.opcode, $1.target); address++;}

instrucao_R: ADD reg comma reg comma reg { $$.opcode = "000000"; $$.rd = $2; $$.rs = $4; $$.rt = $6; $$.shift = "00000"; $$.func = "100101";}

instrucao_J: J IDENTIFICADOR {$$.opcode = "000010"; $$.target = integerToBinary(getOffset(lista, $2), 26, string);}

instrucao_I: ADDI reg comma reg comma NUMBER { $$.opcode = "001000"; $$.imm = $6; $$.rs = $2; $$.rt = $4;}

reg: REG_S {$$ = integerToBinary(getNumber($1), 5, string);}
   | REG_AT {$$ = $1;}
   | REG_T {$$ = $1;}
   | REG_A {$$ = $1;}
   | REG_V {$$ = $1;}
   | REG_K {$$ = $1;}
   | REG_GP {$$ = $1;}
   | REG_SP {$$ = $1;}
   | REG_FP {$$ = $1;}
   | REG_RA {$$ = $1;}
   | REG_ZERO {$$ = $1;}

%%

int yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
  return 0;
}
