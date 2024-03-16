#include "abb.h"

Arvore *criaArvoreVazia()
{
    return NULL;
}

void liberaArvore(Arvore *a)
{
    if (a != NULL)
    {
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
}

//========= Q1 - inserir
Arvore *inserir(Arvore *a, int v)
{
    if (a == NULL)
    {
        Arvore *no = (Arvore *)malloc(sizeof(Arvore));
        no->info = v;
        no->esq = NULL;
        no->dir = NULL;
    }
    else if (v < a->info)
    {
        a->esq = inserir(a->esq, v);
    }
    else
    {
        a->dir = inserir(a->dir, v);
    }

    return a;
}

//========= Q1 - remover
Arvore *remover(Arvore *a, int v)
{
    /* Completar */

    return a;
}

//========= Q1 - busca
int buscar(Arvore *a, int v)
{
    if(a == NULL)
        return 0;
    if(v < a->info)
        buscar(a->dir, v);
    else if(v > a->info)
        buscar(a->esq, v);

    return 1;
}

//========= Q2 - min =====

//========= Q2 - max =====

//========= Q3 - imprime_decrescente =====

//========= Q4 - maior ramo =====

void preOrder(Arvore *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        preOrder(a->esq);
        preOrder(a->dir);
    }
}