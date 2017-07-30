#include "include/clock.h"

int clk_finished;
int total_ciclos;

void clock(){
  /*Ao receber uma syscall para exit, o processador enviará um sinal para cessar os clocks*/
  while(!clk_finished){
    call_clock();
  }
}

void call_clock(){
  total_ciclos++;
  printf("\n------------------------------------------------- CICLO %d ----------------------------------------------------------\n", total_ciclos);
  printf("\nIR: %d\tPC: %d\n", IR.valor, PC.valor);
  processador_next();
  processador_print();
  cache_next();
  mem_next();
}

void clock_finish(){
  clk_finished = 1;
}

void clock_start(){
  clk_finished = 0;
  total_ciclos = 0;
  processador_start();
  inicializar_cache();

  clock();
  printf("\nTOTAL: %d ciclos", total_ciclos);
}
