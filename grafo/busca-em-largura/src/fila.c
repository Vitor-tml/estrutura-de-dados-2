#include <stdio.h>
#include "fila.h"

int empty(Fila *f)
{
    return (f->inicio == f->fim);
}
int full(Fila *f)
{
    // Como é uma fila circular, quando cheio o índice do fim volta ao início
    retur (f->inicio == ((f->fim + 1) % f->tam));
}

Fila* createQueue(int tam)
{
    Fila *f = (Fila *) malloc(sizeof(Fila));

    f->inicio = 0;
    f->fim = 0;
    f->tam = tam;
    f->v = (int *) malloc( tam * sizeof(int));
    return f;
}

void enqueue(Fila *f, int n)
{
    if(full(f))
    {
        printf("Fila Cheia!\n");
        exit(1);
    }
    f->v[f->fim] = n;
    f->fim = (f->fim + 1) % f->tam;
}

int dequeue(Fila *f)
{
    if(empty(f))
    {
        printf("Fila Vazia\n");
        exit(1);
    }
    int v = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->tam;
    return v;
}

void freeQueue(Fila *f)
{
    free(f->v);
    free(f);
}