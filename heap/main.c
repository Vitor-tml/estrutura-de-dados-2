#include <stdio.h>
#include "heap.h"

int main()
{
    int v[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    printf("Vetor inicial:\n");
    imprimir(v);

    buildMaxHeap(v, 10);
    heapSort(v, 10);

    printf("Vetor final:\n");
    imprimir(v);
    
    return 0;
}