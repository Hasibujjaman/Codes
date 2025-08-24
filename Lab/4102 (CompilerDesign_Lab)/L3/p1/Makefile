main: main.c
	gcc -E main.c -o main.i 
	gcc -S main.i -o main.s
	gcc -c main.s -o main.o
	objdump -d main.o
	gcc main.o -o main
	./main
main.s: main.c
	gcc -S main.c -o main.s
clean: 
	rm -f main.i main.s main.o main

