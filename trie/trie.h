#ifndef _TRIE_H_
#define _TRIE_H_

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE 26

// Definição da estrutura

typedef struct trie{
   char data;
   int end;
   int nChild;
   struct trie *keys[SIZE];
} Trie;


// "Métodos" da estrutura

Trie *createNode(char data);
Trie *insert(Trie *root, char *word);
Trie *remove(Trie *root, char *word);
int search(Trie *root, char *word);
void freeNode(Trie *node);
#endif