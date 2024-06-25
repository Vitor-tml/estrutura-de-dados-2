#ifndef _GRAFO_H_
#define _GRAFO_H_

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Definições de constantes
#define BRANCO 1
#define CINZA 2
#define PRETO 3
#define INFTY 0x7FFFFFFF

// Definição da estrutura do vértice
typedef struct no {
    int d;
    int cor;
    int pai;
    int id;
    struct no *next;
} Vertice;

// Definição da estrutura do grafo
typedef struct grafo {
    int e;
    int v;
    Vertice **listaAdj;
} Grafo;

// Protótipos das funções
Grafo *criarGrafo(int tam);
void freeGrafo(Grafo *G);
void inserirAresta(Grafo *G, int a, int b);
void imprimirGrafo(Grafo *G);
void buscaLargura(Grafo *G, int s);

#endif //_GRAFO_H_