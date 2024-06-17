#ifndef _HASH_H
#define _HASH_H

typedef struct hash {
    int key;
} Hash;

Hash* createHash(int M);
void freeHash(Hash *H);
void hashPrint(Hash *H, int M);
int insertHash(Hash *H, int M, int key, int *colisoes);
int searchHash(Hash *H, int M, int key);
#endif