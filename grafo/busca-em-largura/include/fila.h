#ifndef _FILA_H
#define _FILA_H

typedef struct fila{
    int inicio;
    int fim;
    int tam;
    int *v;
} Fila;

int empty(Fila *f);
int full(Fila *f);
Fila* createQueue(int tam);
void enqueue(Fila *f, int n);
int dequeue(Fila *f);

#endif