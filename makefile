CC=gcc
DIR=./include/
TRAD=$(DIR)Tradutor/flexbison/
CFLAGS=-w
LDFLAGS=
SRC= gsim.c
SOURCES= *.c $(DIR)lib/DQueue.c $(DIR)lib/LinkedList.c $(TRAD)parser.tab.c $(TRAD)lex.yy.c $(TRAD)lib/assembler.util.c
# HEADERS=$(SOURCES:.c=.h)
HEADERS=$(DIR)*.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= gsim

all: Clear

main: Montar $(OBJECTS)
	@$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
	@echo "\nCompilado!\n"

Montar:
	+$(MAKE) -C $(DIR)Tradutor/flexbison

Clear: main
	@rm -f *.o
	@rm -f */*.o
	@rm -f */*/*.o
	@rm -f */*/*/*.o
	@rm -f */*/*/*/*.o
