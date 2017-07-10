#include "clock.h"
#include "processador.h"
#include "barramentos.h"

void start(){
  processador_start();

  clock_next();
}

void clock_next(){
  while(Processador_Clock.dado == FLAG_VAZIO){
    Processador_next();
  }
}

int main(){

}
