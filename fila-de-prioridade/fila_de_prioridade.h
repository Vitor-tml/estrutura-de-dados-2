#ifndef _FILA_H
#define _FILA_H

int heapMaximum(int *v);
int headExtractMax(int *v, int size);
void heapIncreaseKey(int *v, int i, int chave);
void maxHeapInsert(int *v, int size, int chave);
#endif