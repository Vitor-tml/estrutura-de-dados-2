#include <stdio.h>
#include <stdlib.h>
#include "grafoM.h"
#include "grafoL.h"

int main()
{
    int v = 10;

    // Alocando memória
    GrafoM* M = criaGrafoMatriz(v);
    GrafoL* L = criaGrafoLista(v);
    
    // Matriz
    criaAdjacenciaM(M, 1, 2, 1);
    criaAdjacenciaM(M, 4, 2, 1);
    criaAdjacenciaM(M, 2, 1, 2);
    // Lista
    criaAdjacenciaL(L, 1, 2, 3);
    criaAdjacenciaL(L, 3, 1, 4);

    // Matriz
    printf("Grafo com Matriz de Adjacencia: \n");
    imprimeMatrizAdj(M);
    printf("Arestas Incidentes de %d: %d\n", 2, arestasIncidentesM(M, 2));
    printf("Arestas Emanantes de %d: %d\n", 2, arestasEmanantesM(M, 2));
    verticesAdjacentesM(M, 2);
    printf("\n\n");
    // Lista
    printf("Grafo com Lista de Adjacencia: \n");
    imprimeListaAdj(L);
    printf("Arestas Incidentes de %d: %d\n", 2, arestasIncidentesL(L, 2));
    printf("Arestas Emanantes de %d: %d\n", 2, arestasEmanantesL(L, 2));
    verticesAdjacentesM(M, 2);

    // Alocando memória
    freeGrafoM(M);
    freeGrafoL(L);
    return 0;
}