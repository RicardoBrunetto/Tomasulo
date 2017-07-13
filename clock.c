#include "clock.h"
#include "processador.h"
#include "barramentos.h"
#include "cache.h"

int total_ciclos;

void start(){
  total_ciclos = 0;
  processador_start();

  clock_next();
}

void clock_next(){
  /*Ao receber uma syscall para exit, o processador enviará um sinal para cessar os clocks*/
  while(Processador_Clock.dado == FLAG_VAZIO){
    total_ciclos++;
    processador_next();
    cache_next();
  }
}

int main(){

}
