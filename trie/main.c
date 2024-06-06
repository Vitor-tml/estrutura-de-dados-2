#include "trie.h"
#include <string.h>
#define ANSI_COLOR_GREEN "\x1b[92m" 
#define ANSI_COLOR_RESET "\x1b[0m"

void printTextBox(const char *text);
void printNumberOfChildren(Trie *root);
int main()
{
  Trie *root = createNode('\0');
  printTextBox("Inserindo");
  root = insertWord(root, "maria");
  root = insertWord(root, "mar");
  root = insertWord(root, "calvo");
  printTrie(root);
  printTextBox("Removendo");
  root = removeWord(root, "mar");
  printTrie(root);
  printTextBox("Procurando");
  printf("Resultado: %d\n", search(root, "mar"));
}


// Fru fru
void printTextBox(const char *text) {
    int length = strlen(text);
    int i;

    // Imprimir linha superior
    printf(ANSI_COLOR_GREEN "\u250C"); // ┌
    for (i = 0; i < length + 2; i++) {
        printf("\u2500"); // ─
    }
    printf("\u2510\n"); // ┐

    // Imprimir linha do texto com margens
    printf("\u2502 %s \u2502\n", text); // │ text │

    // Imprimir linha inferior
    printf("\u2514"); // └
    for (i = 0; i < length + 2; i++) {
        printf("\u2500"); // ─
    }
    printf("\u2518\n" ANSI_COLOR_RESET); // ┘ e resetar a cor
}

void printNumberOfChildren(Trie *root) {
    if (root == NULL) return;

    printf("Número de filhos do nó '%c': %d\n", root->data, root->nChild);

    for (int i = 0; i < SIZE; i++) {
        if (root->keys[i] != NULL) {
            printNumberOfChildren(root->keys[i]);
        }
    }
}