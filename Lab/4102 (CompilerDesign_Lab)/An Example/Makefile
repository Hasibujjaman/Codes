FLEX = flex
BISON = bison

all: compiler

compiler: lex.yy.c example.tab.c
	clang -o compiler example.tab.c lex.yy.c -ll

lex.yy.c: example.l
	$(FLEX) example.l

example.tab.c: example.y
	$(BISON) -d example.y

clean:
	rm -f lex.yy.c example.tab.c example.tab.h compiler
