#include <stdio.h>
#include <stdlib.h>

#include "intro.c"

typedef struct node node;

struct node {
  int data;
  node *next;
};

node *getNode(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if(newNode==NULL) exit(1) ;
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void traverse(node *start) {
  node *loc = start;
  if (!loc) {
    printf("no node exist!\n");
    return;
  }

  printf("\n");
  while (loc) {
    printf("|%d|%X|", loc->data, loc->next);
    if (loc->next) printf(" -> ");
    loc = loc->next;
  }
  printf("\n\n");
}

node *insertAtPosition(node *start, const int position, int data) {
  int currentPosition = 0;
  node *loc, *locp;
  loc = locp = start;

  while (currentPosition < position) {
    locp = loc;
    loc = loc->next;
    currentPosition++;
  }
  node *newNode = getNode(data);
  newNode->next = loc;
  locp->next = newNode;
}
int main() {
  printIntro("inserting at given postion of the linked list.");
  node *start = NULL;
  node *loc = NULL;

  int n;
  printf("how many nodes linked list should contain ? ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    if (start == NULL) {
      loc = getNode(1);
      start = loc;
    } else {
      loc->next = getNode((i + 1) * 3);
      loc = loc->next;
    }
  }
  printf("nodes in linked list : \n");
  traverse(start);

  int position;
  printf("enter position (indexing from 0) where node to be inserted : ");
  scanf("%d", &position);

  if (position < 0 || position > n) {
    printf("invalid position!");
    return 1;
  }

  int data;
  printf("enter data : ");
  scanf("%d", &data);
  if (position == 0) {
    node *newNode = getNode(data);
    newNode->next = start;
    start = newNode;
  } else {
    insertAtPosition(start, position, data);
  }

  printf("\nafter insertion : \n");
  traverse(start);

  return 0;
}