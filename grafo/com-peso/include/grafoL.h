#ifndef _GRAFOL_H
#define _GRAFOL_H

typedef struct no {
    int id;
    int peso;
    struct no *next;
} No;

typedef struct grafoL {
    int e;
    int v;
    No **adj;
} GrafoL;

GrafoL* criaGrafoLista(int tamanho);
void freeGrafoL(GrafoL *G);
void criaAdjacenciaL(GrafoL *M, int a, int b, int peso);
void imprimeListaAdj(GrafoL *G);

#endif