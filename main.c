#include "bstlib.h"

int main(void) 
{
  struct BSTNode *BST = CreateNewBSTNode(10);
  printf("-----------------------------------------------------\nCreating Nodes:\n\n");
  
  InsertBSTNode(BST, 22); // Right
  InsertBSTNode(BST, 2);  // Left
  InsertBSTNode(BST, 11); // Right, Left
  InsertBSTNode(BST, 4); // Left, Right
  InsertBSTNode(BST, 17); // Right, Left, Right
  InsertBSTNode(BST, 8);  // Left, Right, Right

  printf("\n----------------------------------------------------- \nSearching for target:\n\n");

  FindTargetBST(BST, 4);
  
  return 0;
}

