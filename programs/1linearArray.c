#include <stdio.h>

#include "intro.c"

void traverse(int *arr, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  printIntro("creating and traversing an array");
  int n = 6;
  int LA[] = {4, 5, 7, 8, 3, 9};
  
  printf("array created of size %d\nenter item to be stored\n",n) ;
  for(int i = 0 ; i < n ; i++){
	  printf("enter item %d : ",(i+1)) ;
	  scanf("%d",&LA[i]) ;
  }
  printf("Traversing array...\n");
  traverse(LA, n);
  return 0;
}