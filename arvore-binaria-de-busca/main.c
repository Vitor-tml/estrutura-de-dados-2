#include <stdio.h>
#include "abb.h"
#include <time.h>
#define TAM 10000

clock_t inicio, fim;
void inicioContagem();
void fimContagem();
int main()
{
	Arvore *laurelin = criaArvoreVazia();
	Arvore *coqueiro = criaArvoreVazia();
	Arvore *jaqueiro= criaArvoreVazia();
	srand(time(NULL));
	int i;
	// printf("Inserindo: \n");
	// for(i = 0; i < TAM; i++)
	// {
	// 	laurelin = inserir(laurelin, i);
	// 	coqueiro = inserir(coqueiro, rand() % TAM);
	// }


	// inicioContagem();
	// printf("Buscando na laurelin: %d\n", buscar(laurelin, -1));
	// fimContagem();
	// inicioContagem();
	// printf("Buscando no coqueiro: %d\n", buscar(coqueiro, -1));
	// fimContagem();

	jaqueiro = inserir(jaqueiro, 10);
    jaqueiro = inserir(jaqueiro, 5);
    jaqueiro = inserir(jaqueiro, 15);
    jaqueiro = inserir(jaqueiro, 3);
    jaqueiro = inserir(jaqueiro, 7);
    jaqueiro = inserir(jaqueiro, 12);
    jaqueiro = inserir(jaqueiro, 17);

	printf("Árvore com hierarquia:\n");
	imprimir_arvore_vertical(jaqueiro, 0); // supondo que 'laurelin' seja a raiz da árvore

	printf("Jaqueiro %d niveis\n", maiorNivel(jaqueiro));
	for(i = 0; i < 7; i++)
	{
		imprimirArvore(jaqueiro, 0, i, 7, 1);
		printf("\n");
	}
	// AAAAAAAAA nao funciona
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
