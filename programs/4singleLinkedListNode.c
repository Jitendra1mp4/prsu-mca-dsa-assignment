#include <stdio.h>
#include <stdlib.h>
#include "intro.c"

typedef struct node node ;

struct node
{
  int data ;
  node *next ;
};

int main() {
  printIntro("creating a single node in linked list.");

  node *START = NULL ;

  node *loc = (node*)malloc(sizeof(node)) ;
  loc->data = 50 ;
  loc->next = NULL  ;
  START = loc ;
  
  printf("data at node : %d\n",START->data);
  return 0;
}
