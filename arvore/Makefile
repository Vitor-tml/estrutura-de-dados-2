all: main

main: arvore main.c
	gcc main.c arvore.o -o programa

arvore: arvore.c arvore.h
	gcc -c arvore.c -o arvore.o