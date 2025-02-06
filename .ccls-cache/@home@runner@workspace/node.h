// Struct containing Node data.
struct Node {
  struct Node *parent;
  struct Node *next;
  struct Node *Left;
  struct Node *Right;
  unsigned short value;
  unsigned short heuristic;
  unsigned short weight;
};