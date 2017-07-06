#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include "util.h"       /* funções auxiliares */
#include "errormsg.h"   /* erro */
#include "absyn.h"      /* árvore abstrata */
#include "translator.h" /* tradutor */

#define MAX_BUF_LEN		2048

/*
 * Nome do programa
 */
char *program_name;

/*
 * Nome do código fonte
 */
char *infile;

/*
 * Flag para imprimir AST
 */
int print_ast = FALSE;

/*
 * Impressão da versão do frontend
 */
void show_version( void ) {
    puts( "MIPS 32 Assembly Translator version 2.0" );
    exit( EXIT_SUCCESS );
}

/*
 * Impressão de help
 */
void show_help( void ) {
    printf( 
	"Usage: %s [options] [source file]\n"
    	"\n"
	"Valid options:\n"
	"\n"
	"  -a\tPrint abstract syntax tre\n"
	"  -v\tShow version\n" 
	"  -h\tThis help\n", 
	program_name);
    exit( EXIT_SUCCESS );
}

/*
 * Impressão de erro
 */
void argument_error( char * error ) {
    if ( error[0] != '\0' )
	printf( "%s\n", error );
    printf( "\nTry `%s -h' for more information.\n\n", program_name );

    exit( EXIT_FAILURE );
}

/*
 * Processa argumentos de entrada
 */
void parse_args (int argc, char*argv[]) {

  int option;
  int index;

  opterr = 0;

  if (argc == 1)
    argument_error("");

  /* leitura dos parametros de entrada */
  while ((option = getopt(argc, argv, "hva")) != -1)
    switch (option) {
    case 'h':
      show_help();
      break;
    case 'v':
      show_version();
      break;
    case 'a':
      print_ast = 1;
      break;
    case '?':
      if (isprint (optopt))
	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      else
	fprintf (stderr,
		 "Unknown option character `\\x%x'.\n",
		 optopt);
      argument_error("");
      break;
    default:
      argument_error("");
    }

  if (optind > argc-1)
    argument_error("Unknown source file.");

  infile = argv[optind];

  {
    char *ext = strrchr(infile, '.');
    if ((!ext) || (strcmp(ext, ".asm") != 0)) {
      fprintf (stderr, "Invalid source file: %s\n", infile);
      argument_error("");
    }
  }

  *strrchr(infile, '.') = '\0';

  optind++;

  for (index = optind; index < argc; index++)
    fprintf (stderr, "Non-option argument %s\n", argv[index]);

}

/*
 * Programa principal
 */
int main( int argc, char *argv[] ) {
  FILE *out;
  char *filename;
  AST_program ASTroot;
  AST_bin ASTbin;
    
  program_name = argv[0];
  
  parse_args(argc, argv);
  
  filename = strdup(infile);

  ASTroot = T_CreateAST(infile);

  ASTbin = T_Asm2Bin(ASTroot);

  T_WriteBin(ASTbin);
  
  return 1;
}
