#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Struct containing node data.
struct Node {
  struct Node *parent;
  struct Node *next;
  struct Node *Left;
  struct Node *Right;
  unsigned short value;
  unsigned short heuristic;
  unsigned short weight;
};

// this Node pointer function allocates memory for a new Node while assigning it
// a value.
struct Node *CreateNewNode(unsigned short value) {
  // Allocates memory for the new Node.
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->value = value;
  new_node->Left = NULL;
  new_node->Right = NULL;

  return new_node;
}

void InsertNode(struct Node *node, unsigned short value) {
  if (node->value > value) {
    if (node->Left == NULL) {
      printf("CREATING NEW LEFT NODE WITH %hd\n", value);

      node->Left = CreateNewNode(value);
    }

    else {
      printf("%hd is LESS than %hd, going left\n", value, node->value);

      InsertNode(node->Left, value);
    }
  }

  else if (node->value < value) {
    if (node->Right == NULL) {
      printf("CREATING NEW RIGHT NODE WITH %hd\n", value);

      node->Right = CreateNewNode(value);
    }

    else {
      printf("%hd is MORE than %hd, going right\n", value, node->value);

      InsertNode(node->Right, value);
    }
  }
}

bool FindTargetBST(struct Node *node, unsigned short target) {
  if (node->value == target) {
    printf("\nTarget: %hd is EQUAL to Node value: %hd! ", target, node->value);
    printf("Target Found!!!\n");
    return true;
  }

  else if (target > node->value) {
    printf("Target: %hd is MORE than Node value: %hd, going right\n", target,
           node->value);

    return FindTargetBST(node->Right, target);
  }

  else if (target < node->value) {
    printf("Target: %hd is LESS than Node value: %hd, going left\n", target,
           node->value);

    return FindTargetBST(node->Left, target);
  }

  printf("Target not found...\n");
  return false;
}