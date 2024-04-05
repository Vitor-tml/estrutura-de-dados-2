#include <stdio.h>
#include "abb.h"
#include <time.h>
#define TAM 10000

clock_t inicio, fim;
void inicioContagem();
void fimContagem();
int main()
{
	Arvore *jaqueiro= criaArvoreVazia();

	jaqueiro = inserir(jaqueiro, 10);
    jaqueiro = inserir(jaqueiro, 5);
    jaqueiro = inserir(jaqueiro, 15);
    jaqueiro = inserir(jaqueiro, 3);
    jaqueiro = inserir(jaqueiro, 7);
    jaqueiro = inserir(jaqueiro, 12);
    jaqueiro = inserir(jaqueiro, 17);

	imprimeDecrescente(jaqueiro);
	printf("\n");
	jaqueiro = remover(jaqueiro, 10);
	imprimeDecrescente(jaqueiro);
	
	return 0;
}

void inicioContagem()
{
	inicio = clock();
}

void fimContagem()
{
	fim = clock();
	double tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("O tempo de execução foi: %0.10f segundos\n", tempo_decorrido);
}
