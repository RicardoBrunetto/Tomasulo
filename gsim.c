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
  printf("");
}

void waiting(){
  char * input = (char *)malloc(sizeof(char)*200);
  do{
    printf("\n(gsim) ");
    gets(input);
    if(!strcmp(input, "lol")){
      printf("IXTA ERRADO\n");
    }else if(!strcmp(input , "stats")){
      processador_print();
    }else if(!strcmp(input, "print memory")){
      mem_print();
    }else if(!strcmp(input, "print cache")){
      cache_print();
    }else if(!strcmp(input, "help")){
      printHelpMenu();
    }else if(!strcmp(input, "run")){
      processador_start();
      //clock_start();
    }else if(!strcmp(input, "clear")){
      system("clear");
    }else if(!strcmp(input, "show config")){
      show_config();
    }else if(!strcmp(input, "instr help")){
      printf("-> Instruction mnemonic: ");
      gets(input);
      show_instruction_details(input);
    }else if(!strcmp(input, "")){
      //next_step();
      printf("\nenter\n");
    }else if(!strcmp(input, "--continue")){

    }
  }while(strcmp(input, "quit"));
  free(input);
}

int main(int argc, char **argv){
  run_definitions();
  show_config();
  switch (argc){
    case 2:
      if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help")){
          printHelpMenu();
      }
      break;
    case 3:
      if(!strcmp(argv[1], "load")){
        FILE *f = fopen(argv[2], "r");
        call_tradutor(f);
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
