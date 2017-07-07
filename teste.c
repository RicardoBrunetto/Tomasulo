#include <stdio.h>
#include <stdlib.h>

int main(){
  unsigned int x = 2773842605;
  // 41
  // 10
  printf("\n%d", x);
  //unsigned int k = x >> 26;
  unsigned int r = x >> 21;
  printf("\n%d\n", r);
  r = r & 31;
  printf("\n%d\n", r);
}

//'10100101010101010111101010101101
// 00000011111000000000000000000000
/*000000 00000 00000      00000 00000 000000
op        26rs   21 rt   16 rd   11 sh    6 func

op: >> 26 | & 63
rs: >> 21 | & 31
rt: >> 16 | & 31
rd: >> 11 | & 31
sh >> 6 | & 31
func: | & 63*/
