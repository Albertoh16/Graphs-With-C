#include "bstlib.h"

struct Queue 
{
  struct Node *head;
};

void TraverseQueue(struct Node *qNode, struct Node *newNode)
{
    if(qNode->next == NULL)
    {
      qNode->next = newNode;
    }  

    else
    {
      TraverseQueue(qNode->next, newNode);
    }
}

void Enqueue(struct Queue *q, unsigned short value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = value;
  
    if(q->head == NULL)
    {
      q->head = temp;
    }

   else
    {
      TraverseQueue(q->head, temp);
    }
}

struct Node *Dequeue(struct Queue *q)
{
    struct Node *temp = q->head;
    q->head = q->head->next;
    return temp;
}

struct Queue *CreateQueue()
{
  struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
  newQueue->head = NULL;
  return newQueue;
}

bool IsQueueEmpty(struct Queue *q)
{
  if(q->head == NULL)
  {
    return true;
  }

  return false;
}

void PrintQueue(struct Queue *q)
{
  struct Node *item = q->head;
  
  while(item != NULL)
  {
      printf("Value: %d\n", item->value);
      item = item->next;
  }
}