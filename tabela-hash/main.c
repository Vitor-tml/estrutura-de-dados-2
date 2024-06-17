#include <stdio.h>
#include "hash.h"

int main()
{
    int colisoes = 0;
    int M = 11;
    Hash *H = createHash(M);
    insertHash(H, M, 10, &colisoes);
    insertHash(H, M, 22, &colisoes);
    insertHash(H, M, 13, &colisoes);
    insertHash(H, M, 31, &colisoes);
    insertHash(H, M,  4, &colisoes);
    insertHash(H, M, 17, &colisoes);

    printf("Numero de colisoes: %d\n", colisoes);
    hashPrint(H, M);
    freeHash(H);
    return 0;

}