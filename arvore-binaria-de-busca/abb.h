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
Arvore* inserir(Arvore *a, int v);
Arvore* remover(Arvore *a, int v);
Arvore *min(Arvore *a);
Arvore *max(Arvore *a);
void liberaArvore (Arvore* a);
void preOrder(Arvore* a); 
void imprimeDecrescente(Arvore *a);
void imprimir_arvore_vertical(Arvore *raiz, int nivel);
void imprimirArvore(Arvore *a, int nivelAtual, int nivel, int maxNivel, int esquerda);
int buscar (Arvore *a, int v);
int maiorRamo(Arvore *a);
int calculaRamo(Arvore *a, int somaAtual);
int maiorNivel(Arvore *a);
int calculaNivel(Arvore *a, int tamanhoAtual);

#endif
