prob4: prob4.l prob4.y
	bison -d prob4.y        # generates prob4.tab.c and prob4.tab.h
	flex prob4.l            # generates lex.roll.c
	gcc prob4.tab.c lex.roll.c -o roll_parser -lfl
	./roll_parser < input.txt > output.txt



