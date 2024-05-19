#include <stdio.h>

#include "intro.c"

void traverse(int *arr, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void insert(int *arr, int n, int *indexOfLastItem) {
  for (size_t i = 0; i < n; i++) {
    // printf("enter item to be inserted : ");
    // scanf("%d", &arr[i]);
    arr[i] = i * 3;
    *indexOfLastItem += 1;
  }
}

void insertAtPosition(int *arr, int position, int n, int *indexOfLastItem) {
  if (*indexOfLastItem >= n - 1) {
    printf("no more items can be inserted\n ");
    return;
  }

  if (*indexOfLastItem != -1  ) {
    // shift items backward
    for (size_t i = *indexOfLastItem; i >= position; i--) {
      arr[i + 1] = arr[i];
    }
  }
  printf("Enter element to be inserted : ");
  scanf("%d", &arr[position]);
  *indexOfLastItem += 1;
}

int main() {
  printIntro("inserting elements to array using function");
  int n = 10;
  int indexOfLastItem = -1;
  int LA[n];
  int position;

  insert(LA, 6, &indexOfLastItem);
  printf("Array elements :\n");
  traverse(LA, indexOfLastItem);

  printf("\nenter position : ");
  scanf("%d", &position);
  insertAtPosition(LA, position, 10, &indexOfLastItem);
  printf("Array elements :\n");
  traverse(LA, indexOfLastItem);

  return 0;
}