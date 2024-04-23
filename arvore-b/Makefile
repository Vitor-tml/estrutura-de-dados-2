all:: main

main: arvore main.c
	gcc main.c arvore.o -o programa

arvore: arvore.h arvore.c
	gcc -c arvore.c -o arvore.o
