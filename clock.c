#include "include/clock.h"

int total_ciclos;

void clock(){
  /*Ao receber uma syscall para exit, o processador enviará um sinal para cessar os clocks*/
  while(PCB.dados == FLAG_READY){
    total_ciclos++;
    processador_next();
    cache_next();
  }
}

void clock_start(){
  total_ciclos = 0;
  inicializar_cache();
  processador_start();

  clock();
}
