input = input.txt
output = output.txt

main: lexer.l parser.y
	bison -d parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c -o parser
	./parser < $(input) > $(output)

.PHONY: clean
clean:
	rm -f parser lex.yy.c parser.tab.c parser.tab.h $(output)
	


