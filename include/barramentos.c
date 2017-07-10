#include "barramentos.h"

void inicializar_barramentos(){
  CDB.dado = FLAG_VAZIO;
  CDB.endereco = FLAG_VAZIO;

  Cache_Memoria.dado = FLAG_VAZIO;
  Cache_Memoria.endereco = FLAG_VAZIO;

  Processador_Cache.dado = FLAG_VAZIO;
  Processador_Cache.endereco = FLAG_VAZIO;

  Processador_Clock.dado = FLAG_VAZIO;
  Processador_Clock.endereco = FLAG_VAZIO;
}
