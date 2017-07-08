def_parser:
	bison -d def_parser.y
	flex def_scanner.l
	cc -w def_parser.tab.c lex.yy.c ../../definitions.h ../../LinkedList.h ../LinkedList.c -lfl
	echo 'Sucesso - Tradutor!'
