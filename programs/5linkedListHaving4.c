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
  printIntro("linked list having 4 node at compile time");

  node *start = NULL;
  // insertion of first node
  node *loc = getNode(1);
  start = loc;

  loc->next = getNode(2);
  loc = loc->next;

  loc->next = getNode(3);
  loc = loc->next;

  loc->next = getNode(4);
  loc = loc->next;

  printf("node(s) at linked list");
  traverse(start);

  return 0;
}