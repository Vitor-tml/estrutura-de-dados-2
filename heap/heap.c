#include "heap.h"
#include <stdio.h>

int pai(int i)
{
    return ((i-1)/2);
}
int esquerda(int i)
{
    return i * 2 + 1;
}
int direita(int i)
{
    return i * 2 + 2;
}

void trocar(int *v, int a, int b)
{
    int aux;
    aux = v[a];
    v[a] =  v[b];
    v[b] = aux;
}

void imprimir (int V[])
{
   int i;
   for (i = 0; i < SIZE; i++)
        printf("%d ", V[i]);
   printf("\n");
}

void maxHeapify(int *v, int size, int i)
{
    int e = esquerda(i);
    int d = direita(i);
    int maior = i;
    if( e < size && v[e] > v[maior])
        maior = e;
    if( d < size && v[d] > v[maior])
        maior = d;
    if( maior != i)
    {
        trocar(v, maior, i);
        maxHeapify(v, size, maior);
    }
}

void buildMaxHeap(int *v, int size)
{
    int i;
    for(i = size/2 - 1; i >= 0; i--)
        maxHeapify(v, size, i);
}

void heapSort(int *v, int size)
{
    int i;
    for(i = size - 1; i >= 1; i--)
    {
        trocar(v, 0, i);
        maxHeapify(v, i, 0);
    }
}