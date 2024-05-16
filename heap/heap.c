#include <stdio.h>
#include "heap.h"

int pai(int i)
{
    return (i - 1) / 2;
}

void trocar(int V[], int a, int b)
{
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir(int V[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void max_heapify(int V[], int size, int i)
{
    /*TERMINAR*/
}

void build_max_heap(int V[], int size)
{
    /*TERMINAR*/
}

void heap_sort(int V[], int size)
{
    /*TERMINAR*/
}
