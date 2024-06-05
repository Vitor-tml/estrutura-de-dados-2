#include "trie.h"

// Cria nó com "data" sendo a letra inserida
Trie *createNode(char data)
{
  Trie *node = (Trie *) malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nChild = 0;

  int i;
  for(i = 0; i < SIZE; i++)
    node->keys[i] = NULL;

  return node;
}

// Desaloca um nó e todos os seus filhos
void freeNode(Trie *node)
{
  int i;
  for( i = 0; i < SIZE; i++)
    if(node->keys[i] != NULL)
      freeNode(node->keys[i]);

  free(node);
}

// Retorna: 1 - Palavra encontrada 0 - Palavra não encontrada
int search(Trie *root, char *word)
{
  int i = 0;
  int index;
  Trie *t = root;
  
  while(word[i] != '\0')
  {
    index = word[i] - 'a';
    if(t->keys[index] == NULL)
      return FALSE;
    else
      t = t->keys[index];

    i++;
  }

  return (t->end)? TRUE: FALSE;
}

// Insere palavra na trie
Trie *insert(Trie *root, char *word)
{
  if(search(root, word))
  {
    printf("Palavra ja' inserida!\n");
    return root;
  }

  Trie *t = root;
  int i = 0;
  int index;
  while(word[i] != '\0')
  {
    index = word[i] - 'a';
    // Testar se deve adicionar no nChild só quando criar nó ou sempre
    if(t->keys[index] == NULL)
      t->keys[index] = createNode(word[i]);
    t->nChild++;
    t = t->keys[index];
    i++;
  }
  t->end = TRUE;
  return root;
}

// Remove palavra
Trie *remove(Trie *root, char *word)
{
  if(search(root, word))
  {
    printf("Impossivel remover. Palavra %s nao existe na Trie\n");
    return root;
  }

  int i = 0;
  int index;

  while(word[i] != '\0')
  {
    index = word[i] - 'a'; 
    i++;
  }
}