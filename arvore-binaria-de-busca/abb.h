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
Arvore *min(Arvore *a);
Arvore *max(Arvore *a);
void imprimeDecrescente(Arvore *a);
int maiorRamo(Arvore *a);
int calculaRamo(Arvore *a, int somaAtual);
void imprimir_arvore_vertical(Arvore *raiz, int nivel);
int maiorNivel(Arvore *a);
int calculaNivel(Arvore *a, int tamanhoAtual);
void imprimirArvore(Arvore *a, int nivelAtual, int nivel, int maxNivel, int esquerda);

#endif