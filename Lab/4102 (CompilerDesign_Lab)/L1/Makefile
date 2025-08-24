main: cal.l cal.y
	bison -d cal.y
	flex cal.l
	gcc cal.tab.c lex.yy.c -o calc  # Name the executable 'calc'

run:
	./calc < input.txt > output.txt

clean:
	rm -f lex.yy.c output.txt
	rm -f *.out
	rm -f *.tab.c
	rm -f *.tab.h
	rm -f calc  # Also clean up the named executable