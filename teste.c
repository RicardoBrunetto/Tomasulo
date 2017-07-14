#include <stdio.h>
#include <stdlib.h>
/*
int main(){
  unsigned int x = 2773842605;
  // 41
  // 10
  printf("\n%d", x);
  //unsigned int k = x >> 26;
  unsigned int opcode = x >> 26; opcode = opcode & 63;
  unsigned int tgt = x << 16;
  tgt = tgt >> 16;
  printf("\n%d\tImm: %d\n", opcode, tgt);
}
*/
//'10100101010101010111101010101101
// 00000011111000000000000000000000
/*

op: >> 26 | & 63

R

000000  00000 00000 00000 00000 000000
op      26rs  21rt  16rd  11sh  6func

rs: >> 21 | & 31
rt: >> 16 | & 31
rd: >> 11 | & 31
sh >> 6 | & 31
func: | & 63

J

000000  00000000000000000000000000
op      26target

target: << 6 |  >> 6

I

000000  00000 00000 0000000000000000
op      26rs  21rt  16imm

rs: >> 21 | & 31
rt: >> 16 | & 31
imm: << 16 | >> 16


*/
