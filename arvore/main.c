#include "arvore.h"
void imprimeArvore(Arvore *a);

int main (int argc, char *argv[]) 
{
    Arvore *a = constroiArvore ('a', 
                                constroiArvore('b',
                                                criaArvoreVazia(),
                                                constroiArvore('d', 
                                                                criaArvoreVazia(),
                                                                criaArvoreVazia())
                                                                ),
                                constroiArvore('c',
                                                constroiArvore('e', 
                                                                criaArvoreVazia(),
                                                                criaArvoreVazia()
                                                                ),
                                                constroiArvore('f',
                                                                criaArvoreVazia(),
                                                                criaArvoreVazia())
                                                                )
                                );	
    printf( "Qual questao?\n " );
    switch (getchar())
    {
    case '1':
        imprimeArvore(a);
        break;
    case '2':
        imprimeArvore(a);
        break;
    case '3':
        printf( "Qual letra?" );
        printf( "Resultado: %d\n", pertence( a, getchar() ) );
        break;
    case '4':
        printf( "Existem %d nos\n", contaNos(a) );
        break;
    case '5':
        printf( "A altura eh %d\n", calculaAltura(a) );
        break;
    case '6':
        printf( "Existem %d folhass\n", contaFolhas(a) );
        break;
    
    default:
        printf( "Questao invalida\n" );
        break;
    }
    liberaArvore (a);
    return 0;
}

void imprimeArvore(Arvore *a)
{
    printf( "Qual percurso? \na) Pre-order\nb) In-order\nc) Pos-order\n" );
    getchar();
    switch (getchar())
    {
    case 'a':
        preOrder(a);
        break;
    case 'b':
        inOrder(a);
        break;
    case 'c':
        preOrder(a);
        break;
    default:
        printf( "Vc eh burro\n" );
        break;
    }
}