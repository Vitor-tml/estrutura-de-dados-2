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
	rm exe#ifndef ABBLISTA_H
#define ABBLISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* criaArvoreVazia();
void liberaArvore (Arvore* a);
Arvore* inserir(Arvore *a, int v);
Arvore* remover (Arvore *a, int v);
int buscar (Arvore *a, int v);
void preOrder(Arvore* a); 

#endif#include "abb.h"

Arvore *criaArvoreVazia()
{
    return NULL;
}

void liberaArvore(Arvore *a)
{
    if (a != NULL)
    {
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
}

//========= Q1 - inserir
Arvore *inserir(Arvore *a, int v)
{
    if (a == NULL)
    {
        Arvore *no = (Arvore *)malloc(sizeof(Arvore));
        no->info = v;
        no->esq = NULL;
        no->dir = NULL;
    }
    else if (v < a->info)
    {
        a->esq = inserir(a->esq, v);
    }
    else
    {
        a->dir = inserir(a->dir, v);
    }

    return a;
}

//========= Q1 - remover
Arvore *remover(Arvore *a, int v)
{
    /* Completar */

    return a;
}

//========= Q1 - busca
int buscar(Arvore *a, int v)
{
    if(a == NULL)
        return 0;
    if(v < a->info)
        buscar(a->dir, v);
    else if(v > a->info)
        buscar(a->esq, v);

    return 1;
}

//========= Q2 - min =====

//========= Q2 - max =====

//========= Q3 - imprime_decrescente =====

//========= Q4 - maior ramo =====

void preOrder(Arvore *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        preOrder(a->esq);
        preOrder(a->dir);
    }
}#include <stdio.h>
#include "abb.h"

int main()
{
	Arvore *laurelin = criaArvoreVazia();
	inserir(laurelin, 10);
	inserir(laurelin, 5);
	inserir(laurelin, 0);
	inserir(laurelin, 4);
	inserir(laurelin, 2);

	preOrder(laurelin);
	return 0;
}
