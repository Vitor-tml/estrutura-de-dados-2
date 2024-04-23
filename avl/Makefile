all: main

main: avl main.c
	gcc main.c avl.o -o programa

avl: avl.h avl.c
	gcc -c avl.c -o avl.o

clear:
	rm *.o programa
