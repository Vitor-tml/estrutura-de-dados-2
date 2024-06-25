#include <stdio.h>
#include <stdlib.h>
#define BRANCO 1
#define CINZA 2
#define PRETO 3
/*Estrutura para um vértice em uma lista encadeada: */
typedef struct dfs
{
   int d;
   int f;
   int cor;
   int pai;
   int identificador;   /*Identificador do vértice armazenado no nó. */
   struct dfs *proximo; /* Próximo nó na lista encadeada. */
} DFS;
/*Estrutura do Grafo: */
typedef struct grafo
{
   int E;          /* Quantidade de arestas. */
   int V;          /* Quantidade de vértices. */
   DFS **listaAdj; /* Lista de adjacências. */
} Grafo;

void DFS_Visit(Grafo *G, DFS *V, int u, int *tempo)
{
   printf("\t %d", u); // para identificar a componente
   V[u].cor = CINZA;
   *tempo = (*tempo) + 1;
   V[u].d = (*tempo);
   DFS *v;
   for (v = G->listaAdj[u]; v != NULL; v = v->proximo)
   {
      if (V[v->identificador].cor == BRANCO)
      { // printf("Aresta arvore: %2d - %2d\n", u, v->identificador);
         V[v->identificador].pai = u;
         DFS_Visit(G, V, v->identificador, tempo);
      }
      // else {
      // printf("Aresta outra : %2d - %2d\n", u, v->identificador); //}
   }
   V[u].cor = PRETO;
   *tempo = (*tempo) + 1;
   V[u].f = *tempo;
}
/* */
void Busca_Profundidade(Grafo *G)
{
   int u;
   int tempo = 0;
   DFS *V = (DFS *)malloc(G->V * sizeof(DFS));
   for (u = 0; u < G->V; u++)
   {
      V[u].cor = BRANCO;
      V[u].pai = -1;
   }
   for (u = 0; u < G->V; u++)
   {
      if (V[u].cor == BRANCO)
      {
         printf("\nComponente: ");
         DFS_Visit(G, V, u, &tempo);
      }
   }
   printf("\n\nBusca em profundidade:\n");

   for (u = 0; u < G->V; u++)
   {
      printf("%2d = [d : %2d, f : %2d, pai : %2d]\n", u, V[u].d, V[u].f, V[u].pai);
   }
   free(V);
}