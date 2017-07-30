CC=gcc
DIR=./include/
TRAD=$(DIR)lib/parser_def
CFLAGS=-w
LDFLAGS= $(TRAD)/def_parser.tab.c $(TRAD)/lex.yy.c +$(MAKE) -C $(TRAD)
SRC= gsim.c
SOURCES= *.c ula.s $(DIR)Tradutor/parser.tab.c $(DIR)Tradutor/lex.yy.c $(DIR)/Tradutor/lib/assembler.util.c
# HEADERS=$(SOURCES:.c=.h)
HEADERS=$(DIR)*.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= gsim

all: Clear

main: Montar $(OBJECTS)
	@$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) -lfl
	@echo "\nSucesso - Simulador!\n"

Montar:
	+$(MAKE) -C $(DIR)Tradutor

Clear: main
	@rm -f *.o
	@rm -f */*.o
	@rm -f */*/*.o
	@rm -f */*/*/*.o
	@rm -f */*/*/*/*.o
