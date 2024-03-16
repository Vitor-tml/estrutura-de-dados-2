#ifndef ABBLISTA_H
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

#endif