#include "avl.h"

int main () {

   Arvore *AVL = NULL;

   AVL = inserir (AVL, 'Q');
   AVL = inserir (AVL, 'A');
   AVL = inserir (AVL, 'B');
   AVL = inserir (AVL, 'G');
   AVL = inserir (AVL, 'W');
   AVL = inserir (AVL, 'Z');
   /*TERMINAR (INSERIR DEMAIS CHAVES)!!!*/

   //AVL = remover (AVL, 'A');
   //AVL = remover (AVL, 'H');
   //AVL = remover (AVL, 'E');
   //AVL = remover (AVL, 'W');
   //AVL = remover (AVL, 'G');
   //AVL = remover (AVL, 'N');
   //AVL = remover (AVL, 'P');
   //AVL = remover (AVL, 'O');

   imprimirInOrder( AVL, 0 );

   return 0;
}
