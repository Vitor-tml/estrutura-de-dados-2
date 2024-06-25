
#include "grafo.h"

// tam: tamanho da lista de adjacência
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

// Libera a memória do grafo e de todos os nós
void freeGrafo(Grafo *G)
{
    int i;
    Vertice *aux, *temp;
    for(i = 0; i < G->v; i++)
    {
        aux = G->listaAdj[i];
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

// a: de onde o vértice sai b: onde o vértice chega
void inserirAresta(Grafo *G, int a, int b)
{
    Vertice *temp, *ultimo = NULL;

    temp = G->listaAdj[a];
    while(temp != NULL)
    {
        // Verifica se b já é adjacencia de a
        if(temp->id == b)
        {
            printf("Vertice %d ja existe na lista de adj de %d,\n", b, a);
            return;
        }
        ultimo = temp;
        temp = temp->next;
    }

    Vertice *novo = (Vertice *) malloc(sizeof(Vertice));
    novo->id = b;
    novo->next = NULL;
    if(ultimo != NULL) // Se for null a lista de adjacencia de 'a' está vazia
        ultimo->next = novo;
    else
        G->listaAdj[a] = novo;
    
    G->e++;
}

// Nada a comentar, parça
void imprimirGrafo(Grafo *G)
{
    perror("Lista de adjacencia");
    Vertice *aux;
    int i;
    for(i = 0; i < G->v; i++)
    {
        printf("%d \u2192 ", i);
        aux = G->listaAdj[i];
        while (aux != NULL)
        {
            printf("%d ", aux->id);
            aux = aux->next;
        }
        printf("\n");
    }
}

void buscaProfundidade(Grafo *G)
{
    int i;
    int tempo = 0;
    // Cria lista auxiliar de vértices
    Vertice *v = (Vertice *) malloc(G->v * sizeof(Vertice));
    // Inicializa lista auxiliar
    for(i = 0; i < G->v; i++)
    {
        v[i].cor = BRANCO;
        v[i].d = INFTY;
        v[i].pai = -1;
    }
    
    for(i = 0; i < G->v; i++)
    {
        if(v[i].cor == BRANCO)
        {
            printf("\nComponente: ");
            visitaDFS(G, v, i, &tempo);
        }
    }

    printf("Busca em profundidade:\n");
    for(i = 0; i < G->v; i++)
        printf("%2d = [d : %2d, f : %2d, pai : %2d]\n", i, v[i].d, v[i].f, v[i].pai);
    
    free(v);
}

void visitaDFS(Grafo *G, Vertice *V, int i, int *tempo)
{
    Vertice *aux;

    printf("\t %d", i);
    V[i].cor = CINZA;
    *tempo = (*tempo) + 1;
    V[i].d = (*tempo);
    
    aux = G->listaAdj[i];

    while(aux != NULL)
    {
        if(V[aux->id].cor == BRANCO)
        {
            V[aux->id].pai = i;
            visitaDFS(G, V, aux->id, tempo);
        }
        aux = aux->next;
    }
    V[i].cor = PRETO;
    *tempo = (*tempo) + 1;
    V[i].f = *tempo;
}