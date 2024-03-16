#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* criaArvoreVazia ();
Arvore* constroiArvore(Arvore *e, Arvore *d, int c);
void liberaArvore (Arvore* a);

#endif