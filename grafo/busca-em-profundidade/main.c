#include "grafo.h"

int main()
{
    // Número de vértices
    int tamanho = 8; 
    Grafo *G = criarGrafo(tamanho);
    /* 
    Ordem dos vértices da busca em largura vista em aula:
    7 0 1 2
    6 5 4 3
    */
   
    // Inserção das arestas conforme a aula: 
    inserirAresta(G, 0, 7);
    inserirAresta(G, 7, 0);
    inserirAresta(G, 0, 5);
    inserirAresta(G, 5, 0);
    inserirAresta(G, 1, 2);
    inserirAresta(G, 2, 1);
    inserirAresta(G, 1, 4);
    inserirAresta(G, 4, 1);
    inserirAresta(G, 1, 5);
    inserirAresta(G, 5, 1);
    inserirAresta(G, 2, 3);
    inserirAresta(G, 3, 2);
    inserirAresta(G, 2, 4);
    inserirAresta(G, 4, 2);
    inserirAresta(G, 3, 4);
    inserirAresta(G, 4, 3);
    inserirAresta(G, 4, 5);
    inserirAresta(G, 5, 4);
    inserirAresta(G, 6, 7);
    inserirAresta(G, 7, 6);

    imprimirGrafo(G);
    buscaProfundidade(G);
    freeGrafo(G);
    return 0;
}