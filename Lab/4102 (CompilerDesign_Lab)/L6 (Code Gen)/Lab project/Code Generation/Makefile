input = input.txt
output = output.txt

main: lexer.l parser.y
	bison -d parser.y 
	flex lexer.l 
	gcc -o a.out parser.tab.c lex.yy.c
	./a.out < $(input) > $(output)
	



assembler:
	C:\masm32\bin\ml /c /coff /Cp prog1.asm
	C:\masm32\bin\link -entry:main /subsystem:console prog1.obj
	prog1

clean:
	rm -f a.out parser.tab.c parser.tab.h lex.yy.c $(output)
	rm -f prog1.obj prog1.exe
