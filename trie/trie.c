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
  node = NULL;
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
Trie *insertWord(Trie *root, char *word)
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
    t = t->keys[index];
    t->nChild++;
    i++;
  }
  t->end = TRUE;
  return root;
}

// Remove palavra
Trie *removeWord(Trie *root, char *word)
{
  if(!search(root, word))
  {
    printf("Impossivel remover. Palavra %s nao existe na Trie\n", word);
    return root;
  }

  int i = 0;
  int index = 0;
  Trie *t = root;
  
  // Caso onde a palavra  é prefixo de alguma outra
  while(word[i] != '\0')
  {
    //printf("Debug %c\n", word[i]);
    index = word[i] - 'a'; 
    t->keys[index]->nChild--;
    if(t->keys[index]->nChild == 0)
    {
      freeNode(t->keys[index]);
      t->keys[index] = NULL;
      return root;
    }
    t = t->keys[index];
    i++;
  }
  // removeWord a marcação de final de palavra
  t->end = FALSE;

  return root;
}

// imprime as palavras dentro de uma trie (root = raiz da trie, buffer = palavra sendo formada, depth = profundidade atual na trie)
void printWord(Trie *root, char *buffer, int depth)
{
  int i;
  if(root->end)
  {
    buffer[depth] = '\0';
    printf("%s\n", buffer);
  }

  for(i = 0; i < SIZE; i++)
  {
    if(root->keys[i] != NULL)
    {
      buffer[depth] = root->keys[i]->data;
      printWord(root->keys[i], buffer, depth + 1);
    }
  }
}

void printTrie(Trie *root)
{
  // Tamanho máximo das palavras a serem impressas
  char buffer[100];
  printWord(root, buffer, 0);
}