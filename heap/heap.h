#ifndef _HEAP_H
#define _HEAP_H

#define SIZE 10

int pai(int i);
int esquerda(int i);
int direita(int i);
void imprimir (int V[]);
void trocar(int *v, int a, int b);
void maxHeapify(int *v, int size, int i);
void buildMaxHeap(int *v, int size);
void heapSort(int *v, int size);
#endif
