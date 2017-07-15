CC=gcc
DIR=./include/
TRAD=$(DIR)lib/parser_def
CFLAGS=-w
LDFLAGS=
SRC= gsim.c
SOURCES= *.c $(DIR)lib/DQueue.c $(DIR)lib/LinkedList.c $(TRAD)/def_parser.tab.c $(TRAD)/lex.yy.c
# HEADERS=$(SOURCES:.c=.h)
HEADERS=$(DIR)*.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= gsim

all: Clear

main: Montar $(OBJECTS)
	@$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) -lfl
	@echo "\nSucesso - Simulador!\n"

Montar:
	+$(MAKE) -C $(TRAD)
	+$(MAKE) -C $(DIR)Tradutor/flexbison

Clear: main
	@rm -f *.o
	@rm -f */*.o
	@rm -f */*/*.o
	@rm -f */*/*/*.o
	@rm -f */*/*/*/*.o
