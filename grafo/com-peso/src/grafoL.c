#include "grafoL.h"
#include <stdio.h>
#include <stdlib.h>

// Aloca memória par grafo com lista
GrafoL* criaGrafoLista(int tamanho)
{
    int i;
    GrafoL *G = (GrafoL *) malloc(sizeof(GrafoL));
    G->v = tamanho;
    G->e = 0;
    G->adj = (No **) malloc(tamanho * sizeof(No));
    for(i = 0; i < G->v; i++)
        G->adj[i] = NULL;
    return G;
}

// Liberar memória de grafo com lista
void freeGrafoL(GrafoL *G)
{
    int i;
    No *aux, *temp;
    for(i = 0; i < G->v; i++)
        if(G->adj[i] != NULL)
        {
            aux = G->adj[i];
            while(aux != NULL) // Desalocar cada lista encadeada da lista de adjacência
            {
                temp = aux;
                aux = aux->next;
                free(temp);
            }
        }
    free(G->adj);
    free(G);
}


void criaAdjacenciaL(GrafoL *G, int a, int b, int peso)
{
    No *aux;

    // Testa se a adjacência já existe
    aux = G->adj[a];
    while(aux != NULL)
    {
        if(aux->id == b)
            return;
        aux = aux->next;
    }
    
    No *novoNoA = (No*) malloc(sizeof(No));
    novoNoA->id = b;
    novoNoA->peso = peso;
    novoNoA->next = G->adj[a];
    G->adj[a] = novoNoA;

    G->e += 1;
}

void imprimeListaAdj(GrafoL *G)
{
    int i;
    No *aux;
    for(i = 0; i < G->v; i++)
    {
        printf("%d \u2192 ", i);
        aux = G->adj[i];
        while(aux != NULL)
        {
            printf("%d (w:%d)", aux->id, aux->peso);
            aux = aux->next;
        }
        printf("\n");
    }
}