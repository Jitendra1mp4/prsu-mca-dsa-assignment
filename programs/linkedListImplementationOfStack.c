#include <stdio.h>
#include <stdlib.h>

#include "intro.c"
typedef struct node node;
struct node {
  int data;
  node *next;
};

node *createNode(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) {
    printf("overflowed!");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void traverse(node *start) {
  while (start) {
    printf("%d ", start->data);
    start = start->next;
  }
}

int main() {
  printIntro("linked list implementation of stack");
  node *top = NULL;
  printf("Enter\n1 to push\n");
  printf("2 to pop\n");
  printf("3 to print stack\n");
  printf("0 to exit!");
  while (1) {
    int choice;
    printf("\n>>");
    scanf("%d", &choice);
    int data;
    switch (choice) {
      case 1:  // code to push onto stack
        printf("enter data : ");
        scanf("%d", &data);
        node *loc = createNode(data);
        if (top) {
          loc->next = top;
          top = loc;
        } else {
          top = loc;
        }
        break;
      case 2:  // code to pop from stack
        if (top) {
          printf("popped : %d\n", top->data);
          top = top->next;
        } else {
          printf("underflow!\n");
        }
        break;
      case 3:
        printf("printing stack\n");
        traverse(top);
        break;
      default:
        printf("exiting........");
        return 0;
    }
  }
  return 0;
}