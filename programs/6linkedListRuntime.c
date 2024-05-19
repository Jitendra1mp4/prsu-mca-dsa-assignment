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
  if (!loc)
  { printf("no node exist!\n") ;
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
  printIntro("linked list having node(s) at runtime");
  node *start = NULL;
  node *loc = NULL;

  int n;
  printf("how many nodes linked list should contain ?  : ");
  scanf("%d", &n);
  for (int data, i = 0; i < n; i++) {
    printf("Enter data for node %d : ", i + 1);
    scanf("%d", &data);
    if (start == NULL) {
      loc = getNode(data);
      start = loc;
    } else {
      loc->next = getNode(data);
      loc = loc->next;
    }
  }
  printf("nodes of linked list\n") ;
  traverse(start);
  return 0;
}