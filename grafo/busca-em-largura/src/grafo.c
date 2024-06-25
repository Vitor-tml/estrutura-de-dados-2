
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

void buscaLargura(Grafo *G, int s)
{
    int i;
    // Cria lista auxiliar de vértices
    Vertice *v = (Vertice *) malloc(G->v * sizeof(Vertice));
    Vertice *aux;
    // Inicializa lista auxiliar
    for(i = 0; i < G->v; i++)
    {
        v[i].cor = BRANCO;
        v[i].d = INFTY;
        v[i].pai = -1;
    }
    v[s].cor = CINZA;
    v[s].d = 0;
    v[s].pai = -1; // redundante por fins didáticos!
    // Cria fila e coloca a raiz da busca no início
    Fila *F = createQueue(G->v);
    enqueue(F, s);
    // Enquanto a fila não estiver vazia
    while(!empty(F))
    {
        i = dequeue(F);
        aux = G->listaAdj[i];
        while(aux != NULL)
        {
            // Se vértice da lista de adjacência de i estiver marcado como BRANCO na lista de véritces auxiliar
            if(v[aux->id].cor == BRANCO)
            {
                v[aux->id].cor = CINZA;
                // distância = distância do pai + 1
                v[aux->id].d = v[i].d + 1;
                v[aux->id].pai = i;
                enqueue(F, aux->id);
            }
            v[i].cor = PRETO;
            aux = aux->next;
        }
    }
    printf("Busca em largura:\n");
    for(i = 0; i < G->v; i++)
    {
        printf("%d = [d=%2d, pai=%2d]\n", i, v[i].d, v[i].pai);
    }
    free(v);
}