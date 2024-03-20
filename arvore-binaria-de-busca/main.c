#include <stdio.h>
#include "abb.h"
#include <time.h>
#define TAM 30000

clock_t inicio, fim;
void inicioContagem();
void fimContagem();
int main()
{
	Arvore *laurelin = criaArvoreVazia();
	Arvore *coqueiro = criaArvoreVazia();
	srand(time(NULL));
	int i, j;
	printf("Inserindo: \n");
	for(i = 0; i < TAM; i++)
	{
		laurelin = inserir(laurelin, i);
		coqueiro = inserir(coqueiro, rand() % TAM);
	}

	inicioContagem();
	printf("Buscando na laurelin: %d\n", buscar(laurelin, -1));
	fimContagem();
	inicioContagem();
	printf("Buscando no coqueiro: %d\n", buscar(coqueiro, -1));
	fimContagem();
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
