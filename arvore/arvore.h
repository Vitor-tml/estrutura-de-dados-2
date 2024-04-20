#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* criaArvoreVazia (void);
Arvore* constroiArvore (char c, Arvore *e, Arvore *d);
int  verificaArvoreVazia (Arvore *a);
void liberaArvore (Arvore* a);
void posOrder(Arvore *a);
void inOrder(Arvore *a);
void preOrder(Arvore *a);
int pertence(Arvore *a, char c);
int contaNos(Arvore *a);
int max(int a, int b);
int contaFolhas(Arvore *a);
int calculaAltura(Arvore *a);
#endif