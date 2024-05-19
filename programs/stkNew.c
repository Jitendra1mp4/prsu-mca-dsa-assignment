#include <stdio.h>
#include "intro.c"
#define MAX 5  // Defining the maximum size of the stack

int stack[MAX];  // Stack array declaration
int top = -1;    // Stack top initialization

// Function to return the top element from the stack
void peek() {
  if (top >= 0) {
    printf("%d\n", stack[top]);
    return;
  } else {
    printf("Stack is empty\n");
    return;
  }
}
// Function to add an element to the stack
void push(int item) {
  if (top < MAX - 1) {
    top++;
    stack[top] = item;
    printf("pushed %d\n", item);
    return;
  }
  // else
  printf("Stack Overflow\n");
}

// Function to remove the top element from the stack
void pop() {
  if (top >= 0) {
    printf("popped %d\n", stack[top]);
    top--;
    return;
  } else {
    printf("Stack Underflow\n");
    return;
  }
}

int main(int argc, char const *argv[]) {
  printIntro("push operation on array implementation of stack");
  push(12);
  push(16);
  push(18);
  push(19);
  push(21);
  push(31);

  printf("\n");
  pop();
  pop();
  pop();
  pop();
  pop();
  pop();
  return 0;
}
