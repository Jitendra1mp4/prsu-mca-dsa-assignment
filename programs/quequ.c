#include <stdio.h>

#include "intro.c"
#define MAX 5

typedef enum { false, true } boolean;

int FRONT = -1;
int REAR = -1;
int QUEUE[MAX];

boolean isOverflow() {
  if ((FRONT == 0 && REAR == MAX - 1) || FRONT == REAR + 1) return true;
  return false;
}

boolean isUnderflow() {
  if (FRONT == -1) return true;
  return false;
}

void insert(const int item) {
  if (isOverflow()) {
    printf("Overflow!\n");
    return;
  }
  // set rear's value
  if (FRONT == -1) {
    FRONT = REAR = 0;
  } else if (REAR == MAX - 1)
    REAR = 0;
  else
    REAR += 1;
  // set item
  QUEUE[REAR] = item;
}

void delete () {
  if (isUnderflow()) {
    printf("Underflow!\n");
    return;
  }
  // print item
  printf("deleted : %d \n", QUEUE[FRONT]);

  // set FRONT's position
  if (FRONT == REAR) {
    FRONT = REAR = -1;
  } else if (FRONT == MAX) {
    FRONT = 0;
  } else
    FRONT += 1;
}

int main() {
  printIntro("Array implementation of Circler Queue");
  printf(
      "Queue created;\n1 to insert item\n2 to delete from queue\n0 to "
      "exit out of program:\n");
  int s;
  while (true) {
    printf("enter option : ");
    scanf("%d", &s);
    switch (s) {
      case 0:
        return 0;
        break;
      case 1:
        printf("enter item to be inserted : ");
        int data;
        scanf("%d", &data);
        insert(data);
        break;
      case 2:
        delete ();
		break ;
      default:
        printf("enter valid number!\n");
        break;
    }
  }

  return 0;
}
