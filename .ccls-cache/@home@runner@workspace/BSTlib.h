#include <stdio.h>
#include <stdlib.h>

// Struct containing node data.
struct Node 
{
  unsigned short value;
  struct Node *Left;
  struct Node *Right;
};

// this Node pointer function allocates memory for a new Node while assigning it a value.
struct Node *CreateNewNode(unsigned short value)
{
  // Allocates memory for the new Node.
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node -> value = value;
  new_node -> Left = NULL;
  new_node -> Right = NULL;

  return new_node;
}

void InsertNode(struct Node *node, unsigned short value)
{
  if(node -> value > value)
  {
    if(node -> Left == NULL)
    {
      printf("CREATING NEW LEFT NODE\n");
      
      node -> Left = CreateNewNode(value);
    }

    else
    {
      printf("%hd is less than %hd, going left\n", value, node -> value);
      
      InsertNode(node -> Left, value);
    }
  }

  else if(node -> value < value)
  {
    if(node -> Right == NULL)
    {
      printf("CREATING NEW RIGHT NODE\n");
      
      node -> Right = CreateNewNode(value);
    }

    else
    {
      printf("%hd is more than %hd, going right\n", value, node -> value);
      
      InsertNode(node -> Right, value);
    }
  }
}
