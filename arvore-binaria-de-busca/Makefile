all: main
	@echo -e '\e[0;32mExecutando:\e[00m'
	./exe
	@echo ' '

main: arvore
	@echo -e '\e[1;35mCompilando a main:\e[00m'
	gcc main.c abb.o -I ./ -o exe
	@echo ' '

arvore:
	@echo -e '\e[1;35mCompilando a arvore: \e[00m'
	gcc -c abb.c -o abb.o
	@echo ' '

clear:
	rm -rf *.o
	rm exe