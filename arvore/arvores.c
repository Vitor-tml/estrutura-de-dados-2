#include "arvore.h"


Arvore* criaArvoreVazia()
{
   return NULL;
}

Arvore* constroiArvore(Arvore *e, Arvore *d, int c)
{
   Arvore *no = (Arvore*) malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

void liberaArvore (Arvore* a)
{
   if(a != NULL){
      liberaArvore(a->esq);
      liberaArvore(a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====


//========= Exercício 2 - in-ordem ====


//========= Exercício 2 - pós-ordem ====


//========= Exercício 3 - pertence ====


//========= Exercício 4 - conta nós ====


//========= Exercício 5 - calcula altura ====



//========= Exercício 6 - conta folhas ====



int main (int argc, char *argv[])
{

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   arv_libera (a);

   return 0;
}

