#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Struct containing node data.
struct BSTNode {
  unsigned short value;
  struct BSTNode *Left;
  struct BSTNode *Right;
};

// this Node pointer function allocates memory for a new Node while assigning it
// a value.
struct BSTNode *CreateNewBSTNode(unsigned short value) {
  // Allocates memory for the new Node.
  struct BSTNode *new_node = (struct BSTNode *)malloc(sizeof(struct BSTNode));

  new_node->value = value;
  new_node->Left = NULL;
  new_node->Right = NULL;

  return new_node;
}

void InsertBSTNode(struct BSTNode *node, unsigned short value) {
  if (node->value > value) {
    if (node->Left == NULL) {
      printf("CREATING NEW LEFT NODE WITH %hd\n", value);

      node->Left = CreateNewBSTNode(value);
    }

    else {
      printf("%hd is LESS than %hd, going left\n", value, node->value);

      InsertBSTNode(node->Left, value);
    }
  }

  else if (node->value < value) {
    if (node->Right == NULL) {
      printf("CREATING NEW RIGHT NODE WITH %hd\n", value);

      node->Right = CreateNewBSTNode(value);
    }

    else {
      printf("%hd is MORE than %hd, going right\n", value, node->value);

      InsertBSTNode(node->Right, value);
    }
  }
}

bool FindTargetBST(struct BSTNode *node, unsigned short target) {
  if (node->value == target) {
    printf("\nTarget: %hd is EQUAL to Node value: %hd! ", target, node->value);
    printf("Target Found!!!");
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

  printf("Target not found...");
  return false;
}