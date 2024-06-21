#include <stdio.h>
#include "grafoM.h"

// Aloca memória para grafo com matriz
GrafoM* criaGrafoMatriz(int tamanho)
{
    int i;
    GrafoM *G = (GrafoM*) malloc(sizeof(GrafoM));
    G->v = tamanho;
    G->e = 0;
    G->mat = (int **) malloc(tamanho * sizeof(int *));
    for(i = 0; i < G->v; i++)
        G->mat[i] = (int *) malloc(tamanho * sizeof(int));
    return G;
}

// Libera memória de grafo com matriz
void freeGrafoM(GrafoM *G)
{
    int i;
    for(i = 0; i < G->v; i++)
        if(G->mat[i] != NULL)
            free(G->mat[i]);
    
    free(G->mat);
    free(G);
}

// Liga o ponto A ao ponto B (não direcional)
void criaAdjacenciaM(GrafoM *M, int a, int b, int peso)
{
    M->e += 1;
    M->mat[a][b] = peso;
}

void imprimeMatrizAdj(GrafoM *G)
{
    int i, j;
    printf("    ");
    for(i = 0; i < G->v; i++)
        printf("%d ", i);
    // Frufru inicio
    printf("\n  \u250C");
    for(i = 0; i < G->v; i++)
        printf("\u2500\u2500");
    
    printf("\n");
    // Frufru fim
    for(i = 0; i < G->v; i++)
    {
        printf("%d \u2502 ", i);
        for(j = 0; j < G->v; j++)
            printf("%d ", G->mat[i][j]);
        printf("\n");

    }
}

int arestasIncidentesM(GrafoM *G, int v)
{
    int i;
    int arestas = 0;

    for(i = 0; i < G->v; i++)
        if(G->mat[i][v] != 0)
            arestas++;
    return arestas;
}

int arestasEmanantesM(GrafoM *G, int v)
{
    int i;
    int arestas = 0;

    for(i = 0; i < G->v; i++)
        if(G->mat[v][i] != 0)
            arestas++;
    return arestas;
}

void verticesAdjacentesM(GrafoM *G, int v)
{
    int i;
    printf("Vertices adjacentes ao vertice %d: ", v);
    for(i = 0; i < G->v; i++)
        if(G->mat[v][i] != 0 || G->mat[i][v])
            printf("%d ", i);
    printf("\n");
    return;    
}