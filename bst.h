#ifndef structures_h
#define structures_h

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

void InsertNode(struct Node *Node, unsigned short value) {
  if (Node->value > value) {
    if (Node->Left == NULL) {
      printf("CREATING NEW LEFT Node WITH %hd\n", value);

      Node->Left = CreateNewNode(value);
    }

    else {
      printf("%hd is LESS than %hd, going left\n", value, Node->value);

      InsertNode(Node->Left, value);
    }
  }

  else if (Node->value < value) {
    if (Node->Right == NULL) {
      printf("CREATING NEW RIGHT Node WITH %hd\n", value);

      Node->Right = CreateNewNode(value);
    }

    else {
      printf("%hd is MORE than %hd, going right\n", value, Node->value);

      InsertNode(Node->Right, value);
    }
  }
}

bool FindTargetBST(struct Node *Node, unsigned short target) {
  if (Node->value == target) {
    printf("\nTarget: %hd is EQUAL to Node value: %hd! ", target, Node->value);
    printf("Target Found!!!\n");
    return true;
  }

  else if (target > Node->value) {
    printf("Target: %hd is MORE than Node value: %hd, going right\n", target,
           Node->value);

    return FindTargetBST(Node->Right, target);
  }

  else if (target < Node->value) {
    printf("Target: %hd is LESS than Node value: %hd, going left\n", target,
           Node->value);

    return FindTargetBST(Node->Left, target);
  }

  printf("Target not found...\n");
  return false;
}

#endif