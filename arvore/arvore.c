#include "arvore.h"

Arvore* criaArvoreVazia (void) {
   return NULL;
}

Arvore* constroiArvore (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verificaArvoreVazia (Arvore *a) {
   return (a == NULL);
}

void liberaArvore (Arvore* a) {
   if (!verificaArvoreVazia(a)) {
      liberaArvore (a->esq);
      liberaArvore (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====

void preOrder(Arvore *a)
{
    if(a != NULL)
    {
        printf("%c ", a->info);
        preOrder(a->esq);
        preOrder(a->dir);
    }
}
//========= Exercício 2 - in-ordem ====
void inOrder(Arvore *a)
{
    if(a != NULL)
    {
        inOrder(a->esq);
        printf("%c ", a->info);
        inOrder(a->dir);
    }
}

//========= Exercício 2 - pós-ordem ====
void posOrder(Arvore *a)
{
    if(a != NULL)
    {
        posOrder(a->esq);
        posOrder(a->dir);
        printf("%c ", a->info);
    }
}
//========= Exercício 3 - pertence ====

int pertence(Arvore *a, char c)
{
    if(a == NULL)
        return 0;
    
    if(a->info == c)
        return 1;

    return (pertence(a->esq, c) || pertence(a->dir, c));
}
//========= Exercício 4 - conta nós ====

int contaNos(Arvore *a)
{
    if(a == NULL)
        return 0;
    
    return (contaNos(a->esq) + contaNos(a->dir) + 1);
}

//========= Exercício 5 - calcula altura ====

int calculaAltura(Arvore *a)
{
    if(a == NULL)
        return -1;

    return (max(calculaAltura(a->esq), calculaAltura(a->dir)) + 1);
}

int max(int a, int b)
{
    return (a > b)? a : b;
}
//========= Exercício 6 - conta folhas ====

int contaFolhas(Arvore *a)
{
    if(a == NULL)
        return 0;
    
    if(a->esq == NULL && a->dir == NULL)
        return 1;
    else
        return contaFolhas(a->esq) + contaFolhas(a->dir);
}
