all: linkar
	@rm *.o

linkar: arqc assembly
	@gcc -w -m32 ula.o ula.main.o -o ula

arqc:
	@gcc -c -w -m32 ula.main.c -o ula.main.o

assembly:
	@gcc -c -w -m32 -dM ula.s uladefs.h -o ula.o
