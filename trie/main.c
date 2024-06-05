#include "trie.h"

int main()
{
  Trie *root = createNode('\0');

  root = insert(root, "maria");

  printf("Procurando maria: %d\n", search(root, "maria"));
}