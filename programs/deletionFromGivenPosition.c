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

node *deleteFromPosition(node *start, const int position) {
  int currentPosition = 0;
  node *loc, *locp;
  loc = locp = start;

  while (currentPosition < position) {
    locp = loc;
    loc = loc->next;
    currentPosition++;
  }
  locp->next = loc->next;
  printf("\nDELETED : %d, AT ADDRESS : %X\n", loc->data, loc);
  free(loc);
}
int main() {
  printIntro("delete from given postion of the linked list.");
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
  printf("enter position (indexing from 0) node to be deleted from : ");
  scanf("%d", &position);

  if (position < 0 || position >= n) {
    printf("invalid position!");
    return 1;
  }

  if (position == 0) {
    loc = start;
    start = start->next;

    printf("\nDELETED : %d, AT ADDRESS : %X\n", loc->data, loc);
    free(loc);
  } else {
    deleteFromPosition(start, position);
  }

  printf("\nafter Deletion : \n");
  traverse(start);

  return 0;
}