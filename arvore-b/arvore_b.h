#define T 3

typedef struct node{
    int n; // Número de chaves
    int folha; // Booleano
    int chave[2 * T - 1];
    struct node *filhos[2 * T];
}No, Arvore;

Arvore *inserir(Arvore *a, int n);