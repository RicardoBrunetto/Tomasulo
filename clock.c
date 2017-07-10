#include "clock.h"
#include "processador.h"
#include "barramentos.h"

void start(){
  processador_start();

  clock_next();
}

void clock_next(){
  /*Ao receber uma syscall para exit, o processador enviará um sinal para cessar os clocks*/
  while(Processador_Clock.dado == FLAG_VAZIO){
    Processador_next();
  }
}

int main(){

}
