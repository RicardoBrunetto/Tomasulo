%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../definitions.h"

extern FILE *yyin;
%}

%union{
  int integer_value;
  char * string_value;
}

/* declare tokens */
%token DOISPONTOS
%token ABRE_PAR
%token FECHA_PAR
%token <string_value> LBL
%token <integer_value> VAL
%token VIRG
%token PL
%token ECOM

%%
general: spec pl definitions

spec: ECOM LBL DOISPONTOS VAL pl ECOM LBL DOISPONTOS VAL pl ECOM LBL DOISPONTOS VAL pl ECOM LBL DOISPONTOS VAL{
        QUANTIDADE_ESTACOES_RESERVA_ADD = $4;
        QUANTIDADE_ESTACOES_RESERVA_MUL = $9;
        QUANTIDADE_ESTACOES_RESERVA_LOAD = $14;
        QUANTIDADE_ESTACOES_RESERVA_STORE = $19;
        QUANTIDADE_ESTACOES_RESERVA = $4 + $9 + $14 + $19;
      }

definitions: |
            definitions ABRE_PAR LBL DOISPONTOS VAL VIRG VAL VIRG LBL VIRG LBL FECHA_PAR pl {
             Def * d = (Def *)malloc(sizeof(Def));
             d->mnemonic = $3;
             d->opcode = $5;
             d->ciclos = $7;
             d->formato = get_formato_based($9);;
             d->tipo_uf = get_uf_based($11);
             d->function = -1; /*Não possuem Function*/
             d->abstract_opcode = $5; /*Não possuem Abstract Opcode*/
             insertLinkedList(&lista_definicoes, d);
           } |
           definitions ABRE_PAR LBL DOISPONTOS VAL VIRG VAL VIRG LBL VIRG LBL VIRG VAL VIRG VAL FECHA_PAR pl {
             Def * d = (Def *)malloc(sizeof(Def));
             d->mnemonic = $3;
             d->opcode = $5;
             d->ciclos = $7;
             d->formato = get_formato_based($9);;
             d->tipo_uf = get_uf_based($11);
             d->function = $13;
             d->abstract_opcode = $15;
             insertLinkedList(&lista_definicoes, d);
           }

pl:
  | pl PL

%%

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
      yyerror("TIPO INVALIDO DE UNIDADE FUNCIONAL");
}

int get_formato_based(char * formato){
  if(!strcmp(formato, "TYPE_R"))
      return TYPE_R;
  else if(!strcmp(formato, "TYPE_J"))
      return TYPE_J;
  else if(!strcmp(formato, "TYPE_I"))
      return TYPE_I;
  else
      yyerror("TIPO INVALIDO DE INSTRUÇÃO");
}

int run_definitions(){
  inicializarLista(&lista_definicoes);
  yyin = fopen("include/lib/parser_def/def_file.txt", "r");
  do {
		yyparse();
	} while (!feof(yyin));
}

int yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
  return 0;
}
