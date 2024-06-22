#ifndef _GRAFO_H_
#define _GRAFO_H_

typedef struct no{
    int d;
    int cor;
    int pai;
    int id;
    struct  no *next;    
} Vertice;

typedef struct grafo{
    int e;
    int v;
    Vertice **listaAdj;
} Grafo;

Grafo *criarGrafo(int tam);
void *freeGrafo(Grafo *G);

#endif
