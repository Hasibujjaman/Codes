all: roll.l roll.y
	bison -d roll.y
	flex roll.l
	gcc roll.tab.c lex.yy.c -o roll
	./roll < input.txt > output.txt


clean:
	rm -f roll roll.tab.c roll.tab.h lex.yy.c output.txt