

main: prog.l prog.y
	bison -d prog.y
	flex prog.l
	gcc prog.tab.c lex.yy.c -o prog
	./prog < input.txt > output.txt

clean:
	rm -f prog.tab.c prog.tab.h lex.yy.c prog
