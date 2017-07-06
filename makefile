CC=gcc
CFLAGS=-w
LDFLAGS=
SRC= gsim.c
SOURCES= gsim.c processador.c Memoria/memoria.c Tradutor/flexbison/parser.tab.c lib/DQueue.c lib/util.c Registrador/registrador.c EstacoesReserva/estacoesReserva.c
HEADERS=$(SOURCES:.c=.h)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= gsim

all: Clear

main:	Montar $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
	@rm *.o
	@echo 'SUCESSO!'

Montar:
	+$(MAKE) -C Tradutor/flexbison

Clear: main
	@rm */*.o
	@rm */*/*.o
