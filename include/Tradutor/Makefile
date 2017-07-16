all: comp
	@rm -f *.o
	@rm -f */*.o
	@echo "\nSucesso - Assembler!\n"

bison_part:
	@bison -d parser.y

flex_part: bison_part
	@flex scanner.l

comp: flex_part
	@cc -w -c parser.tab.c lex.yy.c ../../include/lib/LinkedList.c lib/assembler.util.c -lfl
	@cc -w -o tradutor parser.tab.o lex.yy.o LinkedList.o assembler.util.o -lfl
