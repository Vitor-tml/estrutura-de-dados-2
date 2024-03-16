#include <stdio.h>
#include "abb.h"

int main()
{
	Arvore *laurelin = criaArvoreVazia();
	inserir(laurelin, 10);
	inserir(laurelin, 5);
	inserir(laurelin, 0);
	inserir(laurelin, 4);
	inserir(laurelin, 2);

	preOrder(laurelin);
	return 0;
}
