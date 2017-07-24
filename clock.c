#include "include/clock.h"

int clk_finished;
int total_ciclos;

void clock(){
  /*Ao receber uma syscall para exit, o processador enviará um sinal para cessar os clocks*/
  while(!clk_finished){
    total_ciclos++;
    processador_next();
    cache_next();
  }
}

void clock_finish(){
  clk_finished = 1;
}

void clock_start(){
  clk_finished = 0;
  total_ciclos = 0;
  inicializar_cache();
  processador_start();

  clock();
}
