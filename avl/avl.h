#ifndef _AVL_H
#define _AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   char chave;
   int altura;
   struct node* esq;
   struct node* dir;
} No, Arvore;

int maior (int esq, int dir);
int altura (Arvore* a);
int atualizarAltura (Arvore *a);
int balanceamento (Arvore *a);
Arvore* rotacaoSimplesEsq (Arvore* a);
Arvore* rotacaoSimplesDir (Arvore* a);
Arvore* rotacaoDuplaEsq (Arvore* a);
Arvore* rotacaoDuplaDir (Arvore* a);
Arvore* atualizarFbDir (Arvore *a);
Arvore* atualizarFbEsq (Arvore *a);
Arvore* inserir (Arvore *a, char chave);
Arvore* remover (Arvore *a, char chave);
void imprimirInOrder(Arvore *a, int nivel);

#endif