#ifndef _GRAFOM_H
#define _GRAFOM_H
#include <stdlib.h>

// Grafo com matriz de adjacência
typedef struct grafoM {
    int e;      // Quantidae de arestas
    int v;      // Quantidade de vértices
    int **mat;  // Matriz de adjacência
} GrafoM;

GrafoM* criaGrafoMatriz(int tamanho);
void freeGrafoM(GrafoM *G);
void criaAdjacenciaM(GrafoM *M, int a, int b, int peso);
void imprimeMatrizAdj(GrafoM *G);
int arestasIncidentesM(GrafoM *G, int v);
int arestasEmanantesM(GrafoM *G, int v);
void verticesAdjacentesM(GrafoM *G, int v);
#endif