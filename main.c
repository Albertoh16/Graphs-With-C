#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "bst.h"

void BstTest()
{
  struct Node *BST = CreateNewNode(10);

  printf("-----------------------------------------------------\nCreating Nodes:\n\n");

  InsertNode(BST, 22); // Right
  InsertNode(BST, 2);  // Left
  InsertNode(BST, 11); // Right, Left
  InsertNode(BST, 4); // Left, Right
  InsertNode(BST, 17); // Right, Left, Right
  InsertNode(BST, 8);  // Left, Right, Right

  printf("\n----------------------------------------------------- \nSearching for target:\n\n");

  FindTargetBST(BST, 4);

  printf("\n----------------------------------------------------- \nPrinting Queue Order:\n\n");
}

void BfsTest(unsigned short puzz, unsigned short target)
{
  
}

int main(void) 
{
  unsigned short goal[3][3] =
  {{1, 2, 3},
   {4, 5, 6},
   {7, 8, 0}};

  unsigned short puzzle[3][3] =
  {{0, 2, 4},
   {6, 1, 3},
   {7, 8, 5}};
  
  struct LinkedList *queue = CreateQueue();

  for(int i = 1; i <= 10; i++)
  {
    Enqueue(queue, i);    
  }
  
  while(!IsQueueEmpty(queue))
  {
      printf("%hd\n", Dequeue(queue)->value);
  }

  return 0;
}