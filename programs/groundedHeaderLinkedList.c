#include <stdio.h>
#include <stdlib.h>

#include "intro.c"

typedef struct node node;

struct node {
  int data;
  node *next;
};

node *getNode(int data, node *start) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) exit(1);
  newNode->data = data;
  newNode->next = NULL;
  start->data += 1 ; // UPDATING VALUE AT HEADER
  return newNode;
}

void traverse(node *start) {
  node *loc = start;
  if (!loc) {
    printf("no node exist!\n");
    return;
  }

  printf("\n");
  while (loc){
    printf("|%d|%X|", loc->data, loc->next);
    if (loc->next) printf(" -> ");
    loc = loc->next;
  }
  printf("\n\n");
}

void insertAtLastNode(node *start, int data) {
  node *loc = start;
  // get last node
  while (loc->next) {
    loc = loc->next;
  } 
  loc->next = getNode(data, start);
}

int main() {
  printIntro("LINKED LIST with header node.");
  node HEADER = {0,NULL}; 
  node *start = &HEADER;
  node *loc = &HEADER;


  int n;
  printf("how many nodes linked list should contain ?  : ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    if (start == NULL) {
      loc = getNode(1, start);
      start->next = loc;
    } else {
      loc->next = getNode((i + 1) * 3, start);
      loc = loc->next;
    }
  }
  printf("nodes in linked list : \n");
  traverse(start);

  int data;
  printf("enter item to be inserted at end : ");

  // creating and inserting node at END
  scanf("%d", &data);
  if (start)
    insertAtLastNode(start, data);
  else
    start->next = getNode(data, start);

  printf("After insertion: \n");
  traverse(start);
  return 0;
}