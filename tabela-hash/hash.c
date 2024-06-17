#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#define EMPTY -0x7FFF // Menor inteiro possível

Hash* createHash(int M)
{
    int i;
    Hash *H = (Hash *) malloc( M * sizeof(Hash) );
    for(i = 0; i < M; i++)
        H[i].key = EMPTY;

    return H;
}

void freeHash(Hash *H)
{
    free(H);
}

void hashPrint(Hash *H, int M)
{
    int i;
    for(i = 0; i < M; i++)
    {
        if(H[i].key != EMPTY)
            printf("%2d - %d\n", i, H[i].key);
        else
            printf("%2d -   \n", i);
    }
}

int sondagemLinear(int chave, int iterador, int M)
{
    return (chave + iterador) % M;
}

int sondagemQuadratica(int chave, int iterador, int M)
{
    return (chave + iterador * iterador) % M;
}

int hashingDuplo(int chave, int iterador, int M)
{
    int R = M - 1; // Tipicamente um número primo menor que M
    int h1 = chave % M;
    int h2 = R - (chave % R);
    return (h1 + iterador * h2) % M;
}

int insertHash(Hash *H, int M, int key, int *colisoes)
{
    int i = 0, j;
    do{
        j = hashingDuplo(key, i, M); //inserir sondagem

        if(H[j].key == EMPTY)
        {
            H[j].key = key;
            return j;
        }
        else
            *colisoes = *colisoes + 1;
        i++;
    } while (i != M );

    return -1;
}

int searchHash(Hash *H, int M, int key)
{
    int i = 0, j;

    do{
        j = sondagemLinear(key, i, M);
        printf("Testando chave: %d\n", j);
        if(H[j].key == key)
            return j;
        i++;
    }while( (i != M) || (H[j].key != EMPTY));
    return -1;    
}