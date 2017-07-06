#include "registrador.h"

void inicializar_registradores(){
  int i;
  for(i=0; i<(sizeof(banco_Registradores)/sizeof(Registrador)); i++){
    banco_Registradores[i].valor = -1;
    banco_Registradores[i].Qi = -1;
  }
  banco_Registradores[0].valor = 0; //Registrador ZERO tem sempre o valor 0
}

int reg_write(int w, int registrador){
  banco_Registradores[registrador].valor = w;
  return w;
}

int reg_read(int registrador){
  if(banco_Registradores[registrador].Qi == -1){ //Se nenhuma ER estiver manipulando o registrador
    return banco_Registradores[registrador].valor;
  }else{
    banco_Registradores[registrador].Qi;
  }
}

int reg_change_status(int registrador, int indice_ER){
  return banco_Registradores[registrador].Qi = indice_ER;
}

void reg_print(int reg){
  printf("\n*--------------------------------------------------*\n*\tReg\t|\tQi\t|\tVALOR\t   *\n*--------------------------------------------------*\n");
  printf("*\t%2d\t|\t%2d\t|\t%10d *\n", reg, banco_Registradores[reg].Qi, banco_Registradores[reg].valor);
  printf("*--------------------------------------------------*\n");
}

void reg_banco_print(){
  int i;
  printf("\n\tBANCO DE REGISTRADORES\n*--------------------------------------------------*\n*\tReg\t|\tQi\t|\tVALOR\t   *\n*--------------------------------------------------*\n");
  for(i = 0; i<(sizeof(banco_Registradores)/sizeof(Registrador)); i++)
    printf("*\t%2d\t|\t%2d\t|\t%10d *\n", i, banco_Registradores[i].Qi, banco_Registradores[i].valor);
  printf("*--------------------------------------------------*\n");
}
