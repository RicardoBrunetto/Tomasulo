#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/gsim.h"

void loadToMemory(FILE *f){
  int address = 0;
  int * val = malloc(sizeof(int));
  while(fread(val, sizeof(int), 1, f) > 0){
    mem_write(*val, address);
    address = address + sizeof(int);
  }
  mem_print();
}

void printHelpMenu(){

}

/*void call_tradutor(char* file_path){
  FILE * f = fopen(file_path, "r");
  yyrestart(f);

  inicializarLista(&lista);
  passada = 0;
  yyparse();
  passada = 1;
  rewind(f);
  yyparse();

  exibirLinkedList(lista);
}*/

void waiting(){
  char * input;
  do{
    printf("(gsim) ");
    gets(input);
    if(!strcmp(input, "lol")){
      printf("IXTA ERRADO\n");
    }else if(!strcmp(input , "stats")){
      processador_print();
    }else if(!strcmp(input, "print memory")){
      mem_print();
    }else if(!strcmp(input, "help")){
      printHelpMenu();
    }else if(!strcmp(input, "run")){
      processador_start();
      //clock_start();
    }
  }while(strcmp(input, "quit"));
}

int main(int argc, char **argv){
  //TODO: load definitions
  switch (argc){
    case 2:
      if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help")){
          printHelpMenu();
      }
      break;
    case 3:
      if(!strcmp(argv[1], "load")){
        /*FILE *f;
        f = fopen(argv[2], "r");
        call_tradutor(f);*/
      }else if(!strcmp(argv[1], "load-b")){
        FILE *f;
        f = fopen(argv[2], "r");
        loadToMemory(f);
      }
      break;
    case 4:
      break;
    default:
      return 0;
  }

  waiting();
}
