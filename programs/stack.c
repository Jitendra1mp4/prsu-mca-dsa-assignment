#define MAX 100 // Defining the maximum size of the stack

char stack[MAX]; // Stack array declaration
int top = -1; // Stack top initialization

// Function to return the top element from the stack
char peek() {
    if(top >= 0) {
        return stack[top];
    } else {
        printf("Stack is empty\n");
        return -1; // Return an invalid character value if the stack is empty
    }
}
// Function to add an element to the stack
void push(char ch) {
    if(top < MAX - 1) {
        top++;
        stack[top] = ch;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to remove the top element from the stack
char pop() {
    if(top >= 0) {
       return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1 ;
    }
}


