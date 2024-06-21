#include <stdio.h>
#include "fila_de_prioridade.h"
#include "heap.h"
int heapMaximum(int *v)
{
    return v[0];
}
int heapExtractMax(int *v, int size)
{
    if(size < 1)
    {
        printf("Erro: heap underflow\n");
        return 0;
    }
    int max = v[0];
    v[0] = v[size - 1];
    size--;
    maxHeapify(v, size, 0);
    return max;

}

void heapIncreaseKey(int *v, int i, int chave)
{
    if (chave < v[i])
    {
        printf("ErroL chave menor que atual.\n");
        return;
    }
    v[i] = chave;
    while( i > 0 && v[pai(i)] < v[i])
    {
        trocar(v, i, pai(i));
        i = pai(i);
    }
}

void maxHeapInsert(int *v, int size, int chave)
{
    size++;
    v[size-1] = -v[0];
    heapIncreaseKey(v, size - 1, chave);
}