#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct LinkedList 
{
  struct Node *head;
  struct Node *tail;
};

struct Node *TraverseQueue(struct Node *qNode, struct Node *newNode)
{
    if(qNode->next == NULL)
    {
      qNode->next = newNode;
      qNode->next->next = NULL;
    }  

    else
    {
      return TraverseQueue(qNode->next, newNode);
    }

  return qNode->next;
}

void Enqueue(struct LinkedList *q, unsigned short value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = value;
  
    if(q->head == NULL)
    {
      q->head = temp;
      q->tail = temp;
    }

   else
    {
      q->tail = TraverseQueue(q->head, temp);
    }
}

struct Node *Dequeue(struct LinkedList *q)
{
    struct Node *temp = q->head;
    q->head = q->head->next;
    return temp;
}

struct LinkedList *CreateQueue()
{
  struct LinkedList *newQueue = (struct LinkedList *)malloc(sizeof(struct LinkedList));
  newQueue->head = NULL;
  newQueue->tail = NULL;
  return newQueue;
}

bool IsQueueEmpty(struct LinkedList *q)
{
  if(q->head == NULL)
  {
    return true;
  }

  return false;
}

void PrintQueue(struct LinkedList *q)
{
  struct Node *item = q->head;
  
  while(item != NULL)
  {
      printf("Value: %d\n", item->value);
      item = item->next;
  }
}