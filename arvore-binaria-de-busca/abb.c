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
        a = (Arvore *) malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
        printf("Inserindo %d\n", a->info);
    }
    else if (v < a->info)
        a->esq = inserir(a->esq, v);
    else if (v > a->info)
        a->dir = inserir(a->dir, v);

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
    else
        return 1;
}

//========= Q2 - min =====

Arvore *min(Arvore *a)
{
    while(a->esq != NULL)
        a = a->esq;
    return a;
}

//========= Q2 - max =====
Arvore *max(Arvore *a)
{
    while(a->dir != NULL)
        a = a->dir;
    return a;
}

//========= Q3 - imprime_decrescente =====
void imprimeDecrescente(Arvore *a)
{
    if(a != NULL)
    {
        imprimeDecrescente(a->esq);
        printf("%d ", a->info);
        imprimeDecrescente(a->dir);
    }
}

//========= Q4 - maior ramo =====

void preOrder(Arvore *a)
{
    if (a != NULL)
    {
        preOrder(a->dir);
        printf("%d ", a->info);
        preOrder(a->esq);
    }
}

int maiorRamo(Arvore *a)
{
    if(a == NULL)
        return 0;

    return calculaRamo(a, 0);
}


int calculaRamo(Arvore *a, int somaAtual)
{
    int somaEsq, somaDir;

    if(a == NULL)
        return 0;

    somaAtual += a->info;

    if(a->esq == NULL && a->dir == NULL)
        return somaAtual;

    somaDir = calculaRamo(a->dir, somaAtual);
    somaEsq = calculaRamo(a->esq, somaAtual);
    
    return (somaDir > somaEsq)? somaDir : somaEsq;
}