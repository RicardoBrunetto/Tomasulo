CC=gcc
CFLAGS=-c -w
LDFLAGS=
SOURCES= memoria.c
HEADERS=$(SOURCES:.c=.h)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= mem

all:	Main
	@echo 'Sucesso - Memória!'

Main:	$(OBJECTS)
	$(CC)	$(CFLAGS) -w $(SOURCES)
