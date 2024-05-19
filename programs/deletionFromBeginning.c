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
  if (newNode == NULL) exit(1);
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

// node *deleteFromPosition(node *start, const int position) {
//   int currentPosition = 0;
//   node *loc, *locp;
//   loc = locp = start;

//   while (currentPosition < position) {
//     locp = loc;
//     loc = loc->next;
//     currentPosition++;
//   }
//   locp->next = loc->next;
//   printf("\nDELETED : %d, AT ADDRESS : %X\n", loc->data, loc);
//   free(loc);
// }
int main() {
  printIntro("delete from firts postion of the linked list.");
  node *start = NULL;
  node *loc = NULL;

  int n;
  printf("how many nodes linked list should contain ? ");
  scanf("%d", &n);
  int data;
  for (int i = 0; i < n; i++) {
    printf("enter data for node %d : ", i + 1);
    scanf("%d", &data);
    if (start == NULL) {
      loc = getNode(data);
      start = loc;
    } else {
      loc->next = getNode(data);
      loc = loc->next;
    }
  }
  printf("\nBEFORE deletion :");
  traverse(start);

  if (start) {
    loc = start;
    start = start->next;
    printf("\nDELETED : %d, AT ADDRESS : %X", loc->data, loc);
    free(loc);
  } else {
    printf("Underflow!");
  }

  printf("\n\nAFTER Deletion :");
  traverse(start);

  return 0;
}