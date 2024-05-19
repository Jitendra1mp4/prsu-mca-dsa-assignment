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
    //printf("pushed %d\n", item);
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

void traverse(){
	if (top < 0) return ;
	for(int i = top ; i >= 0 ; i--){
		printf("%d ",stack[i]) ;
	}
	printf("\n") ;
}

int main() {
  printIntro("implement Stack operation in array using switch case.");  
  printf("Enter\n1 to push\n"); 
  printf("2 to pop\n"); 
  printf("3 to print stack\n"); 
  printf("0 to exit!\n"); 

  while (1) { 
    int choice; 
    printf(">>"); 
    scanf("%d", &choice); 
    int data; 
    switch (choice) { 
      case 1:  // code to call push on stack 
        printf("enter data : "); 
        scanf("%d", &data); 
        push(data) ;
        break; 
      case 2:  // code to call pop from stack 
        pop();
        break; 
      case 3: 
        printf("printing stack\n"); 
        traverse(); 
        break; 
      default: 
        printf("exiting........"); 
        return 0; 
    } 
  } 
  return 0;
}
