#include <stdio.h>
#include <stdlib.h>
#include "grafoM.h"
#include "grafoL.h"

int main()
{
    int v = 10;

    GrafoM* M = criaGrafoMatriz(v);
    GrafoL* L = criaGrafoLista(v);
    
    criaAdjacenciaM(M, 1, 2);
    criaAdjacenciaL(L, 1, 2);

    printf("Grafo com Matriz de Adjacencia: \n");
    imprimeMatrizAdj(M);
    
    printf("Grafo com Lista de Adjacencia: \n");
    imprimeListaAdj(L);

    freeGrafoM(M);
    freeGrafoL(L);
    return 0;
}