#include "avl.h"

// Função que devolve o maior entre dois números inteiros!
int maior(int esq, int dir)
{
    return (esq > dir ? esq : dir);
}

// Retorna a altura de um nó (se for nulo a altura é -1)
int altura(Arvore *a)
{
    if( a == NULL)
        return -1;
    else
        return a->altura;
}

// Retorna a maior altura das subárovores + 1
int atualizarAltura(Arvore *a)
{
    return ( maior( altura(a->esq), altura(a->dir) ) + 1 );
}

// fb(x) = hd(x) - he(x)
int balanceamento(Arvore *a)
{
    return ( altura(a->dir) -  altura(a->esq));
}

// Rotaciona um nó da esquerda para a direita
Arvore *rotacaoSimplesEsq(Arvore *a)
{
    No* t;
    // T é vira o nó que vai subir na rotação
    t = a->dir;
    // A recebe o nó que filho que tinha T
    a->dir = t->esq;
    // A substitui o nó filho que recebeu de T
    t->esq = a;
    // Atualiza altura dos nós manipulados
    a->altura = atualizarAltura(a);
    t->altura = atualizarAltura(t);
    return t; // nova raiz
}

// Rotaciona um nó da direita para a esquerda
Arvore *rotacaoSimplesDir(Arvore *a)
{
    No* t;

    t = a->esq;
    a->esq = t->dir;
    t->dir = a;
    a->altura = atualizarAltura(a);
    t->altura = atualizarAltura(t);
    return t;
}

// Rotaciona primeiro a subárovore a direita e depois a raiz
Arvore *rotacaoDuplaEsq(Arvore *a)
{
    a->dir = rotacaoSimplesDir(a->dir);
    return rotacaoSimplesEsq(a);
}

// Rotaciona primeiro a subárovore a esquerda e depois a raiz
Arvore *rotacaoDuplaDir(Arvore *a)
{
    a->esq = rotacaoSimplesEsq(a->esq);
    return rotacaoSimplesEsq(a);
}

// Atualiza fb realizado rotações à direita
Arvore *atualizarFbDir(Arvore *a)
{
    a->altura = atualizarAltura(a);

    if( balanceamento(a) == -2 ) 
        if( balanceamento(a->esq) <= 0)
            a = rotacaoSimplesDir(a);
        else
            a = rotacaoDuplaDir(a);
    return a;
}

// Atualiza fb realizado rotações à esquerda
Arvore *atualizarFbEsq(Arvore *a)
{
    a->altura = atualizarAltura(a);

    if( balanceamento(a) == 2 )
        if( balanceamento(a->dir) >= 0)
            a = rotacaoSimplesEsq(a);
        else
            a = rotacaoDuplaEsq(a);

    return a;
}

// Insere chave e depois balanceia árvore
Arvore *inserir(Arvore *a, char chave)
{
    if( a == NULL)
    {
        a = (No*) malloc( sizeof(No) );
        a->chave = chave;
        a->altura = 0;
        a->esq = a->dir = NULL;
    }
    else if( chave < a->chave )
    {
        a->esq = inserir( a->esq, chave );
        a = atualizarFbEsq(a);
    }
    else
    {
        a->dir = inserir( a->dir, chave );
        a = atualizarFbDir(a);
    }
    return a;
}

//Função para remover um nó de uma árvore binária de busca balanceada!
Arvore *remover(Arvore *a, char chave)
{

    if (a == NULL)
        return NULL;

    if (chave < a->chave)
    {
        a->esq = remover(a->esq, chave);
        a = atualizarFbDir(a);
    }
    else if (chave > a->chave)
    {
        a->dir = remover(a->dir, chave);
        a = atualizarFbEsq(a);
    }
    else
    {
        if ((a->esq == NULL) && (a->dir == NULL))
        {
            free(a);
            a = NULL;
        }
        else if (a->esq == NULL)
        {
            No *tmp = a;
            a = a->dir;
            free(tmp);
        }
        else if (a->dir == NULL)
        {
            No *tmp = a;
            a = a->esq;
            free(tmp);
        }
        else
        {
            No *tmp = a->esq;
            while (tmp->dir != NULL)
            {
                tmp = tmp->dir;
            }
            a->chave = tmp->chave;
            tmp->chave = chave;
            a->esq = remover(a->esq, chave);
            a = atualizarFbDir(a);
        }
    }
    return a;
}


/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimirInOrder(Arvore *a, int nivel)
{
    if (a != NULL)
    {
        int i;
        for ( i = 0; i < nivel; i++ )
        {
            printf("      ");
        }
        printf( "Chave: %c ( altura: %d, fb: %+d ) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel );
        imprimirInOrder( a->esq, nivel + 1 );
        imprimirInOrder( a->dir, nivel + 1 );
    }
}
