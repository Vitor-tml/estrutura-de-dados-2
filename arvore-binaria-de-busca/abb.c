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

//========= DESAFIO - Imprimir estruturada =====

int maiorNivel(Arvore *a)
{
    if(a == NULL)
        return 0;

    return calculaNivel(a, 0);
}

int calculaNivel(Arvore *a, int tamanhoAtual)
{
    int esq;
    int dir;

    if(a == NULL)
        return 0;

    tamanhoAtual++;
    if(a->esq == NULL && a->dir == NULL)
        return tamanhoAtual;

    esq = calculaNivel(a->esq, tamanhoAtual);
    dir = calculaNivel(a->dir, tamanhoAtual);
    
    return (dir > esq)? dir : esq;
}


void imprimirArvore(Arvore *a, int nivelAtual, int nivel, int maxNivel, int esquerda)
{
    // PROBLEMAS:
    /*
        1. Arrumar a impressão de nós vazios (quando nivelAtual == nivel e a == NULL deve imprimir um espaço)
        2. Arrumar o espaçamento para quando existirem vários níveis
        3. Quando for imprimir a esquerda novamente de um mesmo nível continua usando vários tabs 
    */
    if (a != NULL)
    {
        imprimirArvore(a->esq, nivelAtual + 1, nivel, maxNivel, 1);
        if(nivelAtual == nivel)
        {
            if(esquerda)
                for(int i = 0; i < maxNivel - nivelAtual; i++)
                    printf("\t");
            else
                printf("\t\t");
            printf("%d", a->info);
        }
        imprimirArvore(a->dir, nivelAtual + 1, nivel, maxNivel, 0);
    }

}
void imprimir_arvore_vertical(Arvore *raiz, int nivel) {
    if (raiz != NULL) {
        imprimir_arvore_vertical(raiz->dir, nivel + 1); // imprime subárvore direita com um nível a mais
        for (int i = 0; i < nivel; i++) {
            printf("\t"); // imprime espaços para representar a hierarquia
        }
        printf("%d\n", raiz->info); // imprime o valor do nó
        imprimir_arvore_vertical(raiz->esq, nivel + 1); // imprime subárvore esquerda com um nível a mais
    }
}
