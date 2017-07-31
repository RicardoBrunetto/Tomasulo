#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/gsim.h"

void loadToMemory(FILE *f){
  int address = START_ADDRESS_DATA;

  /*Data loading*/
  int i, instr = 0, lines = (DATA_AMOUNT/WORD_SIZE), val;
  for(i=0; i<lines; i++){
    fread(&val, WORD_SIZE, 1, f);
    mem_write(val, address);
    address = address + WORD_SIZE;
  }
  /*Text loading*/
  address = 0;
  while(fread(&val, WORD_SIZE, 1, f) > 0){
    mem_write(val, address);
    address = address + WORD_SIZE;
  }

  printf("\n-> Binario carregado na memoria.\n-> Digite \"run -d\" para inciar o processamento.\n");
}

void printHelpMenu(){
  printf("\t\tMenu de ajuda do GSIM\n");
  printf("Comandos disponiveis:\n");
  printf("\tstats\t\t: Mostra o status do processador no momento da execucao\n");
  printf("\tprint memory\t\t: Mostra a memória RAM (tamanho atual de %d bytes)\n", MEM_SIZE);
  //printf("\tprint cache\t\t: Mostra a cache completa [Nao implementado]\n");
  printf("\trun\t\t: Inicia o processamento\n");
  printf("\t\t-d\t: Mostra o processador a cada ciclo de clock [Estacoes de Reserva, Banco de Registradores e Fila de Instrucoes]\n");
  printf("\t\t*Inicialmente, o pulso de clock se emite a cada [ENTER]. O comando \"continue\" finaliza o processamento (ciclo continuo).\n");
  printf("\tshow config\t\t: Mostra as configuracoes atuais do GSIM (instrucoes reconhecidas e quantidades de Estacoes de Reserva)\n");
  printf("\tinstr help\t\t: Mostra um menu para detalhes de uma instrucao especifica\n");
  printf("\tclear\t\t: Limpa o terminal\n");
  printf("\tquit\t: Encerra o GSIM\n\n");
}

void waiting(){
  char * input = (char *)malloc(sizeof(char)*200);
  do{
    printf("\n(gsim) ");
    gets(input);
    if(!strcmp(input , "stats")){
      processador_print();
    }else if(!strcmp(input, "print memory")){
      mem_print();
    }else if(!strcmp(input, "print cache")){
      cache_print();
    }else if(!strcmp(input, "help")){
      printHelpMenu();
    }else if(!strcmp(input, "run -d")){
      MODULE = FLAG_VERBOSE;
      printf("\n-> Digite [ENTER] para avancar um ciclo de clock\n");
      printf("\n-> Digite \"continue\" para ir ate o final da execucao\n");
      clock_start();
    }else if(!strcmp(input, "run")){
      clock_start();
      clock();
    }else if(!strcmp(input, "clear")){
      system("clear");
    }else if(!strcmp(input, "show config")){
      show_config();
    }else if(!strcmp(input, "instr help")){
      printf("-> Instruction mnemonic: ");
      gets(input);
      show_instruction_details(input);
    }else if(!strcmp(input, "")){
      call_clock();
    }else if(!strcmp(input, "continue")){
      clock();
    }else{
      printHelpMenu();
    }
  }while(strcmp(input, "quit"));
  free(input);
}

int main(int argc, char **argv){
  run_definitions();
  mem_init();
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
        f = fopen("output/output", "r");
        loadToMemory(f);
      }else if(!strcmp(argv[1], "load-b")){
        FILE *f;
        f = fopen(argv[2], "r");
        loadToMemory(f);
      }
      break;
    case 4:
      break;
    default:
      printHelpMenu();
  }

  waiting();
}
