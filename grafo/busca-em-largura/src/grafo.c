#include <stdlib.h>
#include "grafo.h"

Grafo *criarGrafo(int tam)
{
    int i;
    Grafo *G = (Grafo *) malloc(sizeof(Grafo));
    G->e = 0;
    G->v = tam;
    G->listaAdj = (Vertice **) malloc(tam * sizeof(Vertice *));
    for(i = 0; i < G->v; i++)
        G->listaAdj[i] = NULL;
    return G;
}

void *freeGrafo(Grafo *G)
{
    int i;
    Vertice *aux, *temp;
    for(i = 0; i < G->v; i++)
    {
        aux - G->listaAdj[i];
        while(aux != NULL)
        {
            temp = aux;
            aux = aux->next;
            free(temp);
        }
    }
    free(G->listaAdj);
    free(G);
}

