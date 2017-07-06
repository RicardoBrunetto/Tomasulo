#include <stdlib.h>
#include <stdio.h>

int main(){
  FILE *f;
  f = fopen("teste.txt", "w");
  int buffer [] = {12, 15, 27, 309, 15123};
  fwrite(buffer, sizeof(int), sizeof(buffer), f);
}
