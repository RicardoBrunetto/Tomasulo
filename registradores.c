#include "include/registradores.h"

void inicializar_registradores(){
  int i;
  for(i=0; i<(sizeof(banco_Registradores)/sizeof(Registrador)); i++){
    banco_Registradores[i].valor = 0;
    banco_Registradores[i].Qi = FLAG_DISPONIVEL;
  }
  banco_Registradores[0].valor = 0; //Registrador ZERO tem sempre o valor 0
}

int reg_write(int w, int registrador){
  if(registrador == 0) return 0; //Não permite escrever no registrador ZERO
  banco_Registradores[registrador].valor = w;
  return w;
}

int reg_read(int registrador){
  return banco_Registradores[registrador].valor;
}

int reg_get_status(int registrador){
  return banco_Registradores[registrador].Qi;
}

int reg_change_status(int registrador, int indice_ER){
  if(registrador == 0) return 0; //Não permite alterar o registrador ZERO
  return banco_Registradores[registrador].Qi = indice_ER;
}

char * get_nome_reg(int indice){
  switch (indice) {
    case 0: return "z";
    case 1: return "at";
    case 2: return "v0";
    case 3: return "v1";
    case 4: return "a0";
    case 5: return "a1";
    case 6: return "a2";
    case 7: return "a3";
    case 8: return "t0";
    case 9: return "t1";
    case 10: return "t2";
    case 11: return "t3";
    case 12: return "t4";
    case 13: return "t5";
    case 14: return "t6";
    case 15: return "t7";
    case 16: return "s0";
    case 17: return "s1";
    case 18: return "s2";
    case 19: return "s3";
    case 20: return "s4";
    case 21: return "s5";
    case 22: return "s6";
    case 23: return "s7";
    case 24: return "t8";
    case 25: return "t9";
    case 26: return "k0";
    case 27: return "k1";
    case 28: return "gp";
    case 29: return "sp";
    case 30: return "fp";
    case 31: return "ra";
    case 32: return "hi";
    case 33: return "lo";
  }
}

void reg_print(int reg){
  printf("\n*--------------------------------------------------*\n*\tReg\t|\tQi\t|\tVALOR\t   *\n*--------------------------------------------------*\n");
  printf("* [%2d]\t%s\t|\t%2d\t|\t%10d *\n",reg, get_nome_reg(reg), banco_Registradores[reg].Qi, banco_Registradores[reg].valor);
  printf("*--------------------------------------------------*\n");
}

void reg_banco_print(){
  int i;
  printf("\n\tBANCO DE REGISTRADORES\n*--------------------------------------------------*\n*\tReg\t|\tQi\t|\tVALOR\t   *\n*--------------------------------------------------*\n");
  for(i = 0; i<(sizeof(banco_Registradores)/sizeof(Registrador)); i++)
    printf("* [%2d]\t%s\t|\t%2d\t|\t%10d *\n", i, get_nome_reg(i), banco_Registradores[i].Qi, banco_Registradores[i].valor);
  printf("*--------------------------------------------------*\n");
}
