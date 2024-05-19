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

int main() {
  printIntro("inserting at end of the linked list.");
  node *start = NULL;
  node *loc = NULL;

  int n;
  printf("how many nodes linked list should contain ?  : ");
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

  int data;
  printf("enter item to be inserted at first position : ");

// creating and inserting node at first postion
  scanf("%d", &data);
  node *newNode = getNode(data);
  newNode->next = start;
  start = newNode;

  printf("nodes in linked list after insertion: \n");
  traverse(start);
  return 0;
}