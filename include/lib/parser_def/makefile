all: comp
	@rm -f *.o
	@rm -f */*.o
	@echo "\nSucesso - Definidor!\n"

bison_part:
	@bison -d def_parser.y

flex_part: bison_part
	@flex def_scanner.l

comp: flex_part
	@cc -w -c def_parser.tab.c lex.yy.c ../LinkedList.c -lfl
