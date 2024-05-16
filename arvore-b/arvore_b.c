#include "arvore_b.h"
#include <stdio.h>
#define ARVORE_VAZIA NULL
#define FOUND 1
#define NOT_FOUND -1
typedef int Chave;

Arvore *inserir(Arvore *a, int n)
{
    if(a == NULL)
    {
        Arvore* novoNo = (Arvore *) malloc(sizeof(Arvore));
        
    } 
    
}

int busca(Arvore *a, Chave k)
{
	int i = 0;
	while( (i < a->n) && (k > a->chave[i]) )
		i++;
	if( (i < a->n) && (k == a->chave[i]) )
		return FOUND;
	else if(a->folha)
		return NOT_FOUND;
	else
		return busca(a->filhos[i], k);
}
