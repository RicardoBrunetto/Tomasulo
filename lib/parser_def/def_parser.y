%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Definitions/definitions.h"

%}

/* declare tokens */
%token DOISPONTOS
%token ABRE_PAR
%token FECHA_PAR
%token LBL
%token VAL
%token VIRG
%token PL

%%
general: definitions

definitions: |
            definitions ABRE_PAR LBL DOISPONTOS VAL VIRG VAL VIRG VAL FECHA_PAR pl {
              printf("\n\t%d\t%d\t%d\n", $6, $8, $10);
             Def * d = (Def *)malloc(sizeof(Def));
             d->opcode = $6;
             d->ciclos = $8;
             d->tipo_uf = $10;
             insertLinkedList(&lista_definicoes, d);
           }

pl:
  | pl PL

%%

int main(){
  inicializarLista(&lista_definicoes);
  yyparse();
  printf("\n%d", getSizeofLinkedList(lista_definicoes));
  Def * d;
  while((d = (Def *)getProximoLinkedList(&lista_definicoes)) != NULL)
    printf("\n\t%d\t%d\t%d\n", d->opcode, d->ciclos, d->tipo_uf);
  resetProximoLinkedList(&lista_definicoes);
}

int yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
  return 0;
}
