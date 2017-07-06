#ifndef  _ABSYN_H_
#define  _ABSYN_H_

#include "symbol.h"

/*
  Implemente aqui a estrutura de uma �rvore

  O objetivo � ter uma representa��o da entrada em mem�ria.

*/

typedef struct AST_program_ *AST_program;
typedef struct AST_bin_     *AST_bin;

struct AST_program_ {
  int a;
  int b;
};

struct AST_bin_ {
  int a;
  int b;
};


AST_program AST_root;

#endif
