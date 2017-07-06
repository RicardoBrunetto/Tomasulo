TOPDIR = ..

PROG  = asm2bin
FASE  = Translator
LEX   = lex
BISON = bison
AR    = ar

INCDIR = $(TOPDIR)/$(FASE)
OUTDIR = $(TOPDIR)/$(FASE)
SRCDIR = $(TOPDIR)/$(FASE)
OBJDIR = $(TOPDIR)/$(FASE)/tmp

# set VPATH so make knows where to look for source files
VPATH += $(SRCDIR)

OBJS = 	errormsg.o \
	hashtable.o \
	translator.o \
	util.o \
	absyn.o \
	symbol.o \
	asm2bin.o \
	grammar.tab.o \
	lex.yy.o 

OBJECTS = $(OBJS:%=$(OBJDIR)/%)

CFLAGS =  -g -I./$(INCDIR)  

all: $(PROG)

lex.yy.c: lexico.l 
	@echo Compiling $< ; \
	rm -f $@ ; \
	$(LEX) lexico.l

grammar.tab.c: grammar.y lex.yy.c 
	@echo Compiling $< ; \
	rm -f $@ ; \
	$(BISON) -d -t -v grammar.y

$(OBJDIR)/%.o: %.c
	@echo Compiling $< ; \
	rm -f $@ ; \
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(OBJDIR)/$*.o

$(PROG): $(OBJECTS)
	@echo Making $(PROG); \
	rm -f $@; \
	$(CC) $(LDFLAGS) -o $(OUTDIR)/$@ $(OBJECTS); \

clean: 
	$(RM) -f $(PROG) $(OBJECTS) lex.yy.c asm2bin.output asm2bin.tab.c asm2bin.tab.h  *~





