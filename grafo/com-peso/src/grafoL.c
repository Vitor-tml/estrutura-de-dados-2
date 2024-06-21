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

void verticesAdjacentesL(GrafoL *G, int v)
{
    int i;
    No *aux;
    printf("Vertices adjacentes a %d: ", v);
    // Imprime as arestas que apontam pra V
    for(i = 0; i < G->v; i++)    
    {
        aux = G->adj[i];
        while(aux != NULL)
        {
            // Se for a lista de adjacencia do próprio vertice ou se o vértice está na lista de de adjacencia de outro
            if(aux->id == v || i == v)
            {
                // Caso esteja na lista de adjacencia do próprio vértice imprime o ID do nó, senão imprime o ID da lista de adj
                printf("%d ", (i == v)? aux->id: i);
                break;
            }
        }  
    }      
    // Imprime as arestas que saem de V
    printf("\n");
}
int arestasIncidentesL(GrafoL *G, int v)
{
    int i, arestas = 0;
    No *aux;
    for(i = 0; i < G->v; i++)
    {
        aux = G->adj[i];
        while(aux != NULL)
        {
            if(aux->id == v)
            {
                arestas++;
                break;
            }
            aux = aux->next;
        }        
    }
    return arestas;
}
int arestasEmanantesL(GrafoL *G, int v)
{
    No *aux = G->adj[v];
    int arestas = 0;
    printf("Arestas Emanantes de %d: ", v);
    while(aux != NULL)
    {
        arestas++;
        aux = aux->next;
    }
    return arestas;
}