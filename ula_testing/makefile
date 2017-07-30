all: linkar
	@rm *.o

linkar: arqc assembly
	@gcc -w ula.o ula.main.o -o ula

arqc:
	@gcc -c -w ula.main.c -o ula.main.o

assembly:
	@gcc -c -w ula.s -o ula.o
