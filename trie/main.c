#include "trie.h"

int main () {

  Trie *root = create_node ('\0');

  root = insert (root, "maria");
  root = insert (root, "mariadesaparecida");
  root = insert (root, "abacate");
  root = insert (root, "acabado");
  root = insert (root, "abacaxi");
  root = insert (root, "maribondo");
  

  //print (root, 0);

  search (root, "maria");
  print_all(root);
  delete(root, "maria");
  print_all(root);
  //print (root, 0);

  return 0;
}
