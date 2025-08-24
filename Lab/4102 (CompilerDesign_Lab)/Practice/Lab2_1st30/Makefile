main: cal.l cal.y
	bison cal.y
	flex cal.l
	gcc cal.tab.c lex.yy.c
	./a.out < input.txt > output.txt

main2: prog.l prog.y
	bison -d prog.y
	flex prog.l
	gcc prog.tab.c lex.yy.c
	./a.out <input.txt> output.txt