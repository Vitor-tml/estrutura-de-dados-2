#include "trie.h"
#define NOT_FOUND 0
/* */
Trie *create_node(char data)
{
  Trie *node = (Trie *)malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nchild = 0;
  int i;
  // size is the alphabet size
  for (i = 0; i < size; i++)
  {
    node->keys[i] = NULL;
  }
  return node;
}

/* */
void free_node(Trie *node)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (node->keys[i] != NULL)
    {
      free_node(node->keys[i]);
    }
  }
  free(node);
}

/* */
Trie *insert(Trie *root, char *word)
{
  if (search_auxiliary(root, word))
  {
    printf("ERRO! Palavra ja' inserida\n");
    return root;
  }
  Trie *t = root;
  int i, index;

  for (i = 0; word[i] != '\0'; i++)
  {
    index = word[i] - 'a';
    if (t->keys[index] == NULL)
      t->keys[index] = create_node(word[i]);
    t->nchild += 1;
    t = t->keys[index];
  }
  t->end = TRUE;
  return root;
}

/* */
int search_auxiliary(Trie *root, char *word)
{
  Trie *t = root;
  int i, index;
  for (i = 0; word[i] != '\0'; i++)
  {
    index = word[i] - 'a';
    if (t->keys[index] == NULL)
      return FALSE;
    else
      t = t->keys[index];
  }
  return t->end; // sendo TRUE ou FALSE
}

void search(Trie *root, char *word)
{
  if (search_auxiliary(root, word))
    printf("Word \"%s\" found!\n", word);
  else
    printf("Error: word \"%s\" not found!\n", word);
}

/* */
void print(Trie *root, int level)
{
  if (root != NULL)
  {
    int i;
    if (root->data == '\0')
      printf("(null)");
    for (i = 0; i < level; i++)
    {
      printf("| ");
    }
    printf("%c (%d - %d)\n", root->data, root->end, root->nchild);
    for (i = 0; i < size; i++)
    {
      print(root->keys[i], level + 1);
    }
  }
}

void delete(Trie *root, char *word)
{
  int i = 0;
  int index;
  Trie aux;
  Trie checkpont; // Última letra que é prefixo

  while(word[i] != '\0')
  {
    index = word[i] - 'a';

    if()
  }
}

void print_all_words(Trie *root, char buffer[], int depth)
{
  if (root == NULL)
    return;

  // Se o nó atual representa o final de uma palavra,
  // imprime o conteúdo do buffer, que armazena a palavra.
  if (root->end)
  {
    buffer[depth] = '\0';
    printf("%s\n", buffer);
  }

  int i;
  for (i = 0; i < size; i++)
  {
    // Se o nó filho não for nulo, adiciona a letra correspondente ao buffer.
    if (root->keys[i] != NULL)
    {
      buffer[depth] = 'a' + i;
      print_all_words(root->keys[i], buffer, depth + 1);
    }
  }
}

void print_all(Trie *root)
{
  char buffer[100]; // Tamanho arbitrário do buffer para armazenar palavras
  print_all_words(root, buffer, 0);
}