#include <stdio.h>

#include "intro.c"

void deleteFromPosition(int *arr, const int position, int *indexOfLastItem) {
  if (position < 0 || position > *indexOfLastItem) {
    printf("\nCan not be deleted!");
    return;
  }
  printf("\ndeleted item : %d\n", arr[position]);
  // move items forward
  for (size_t i = position; i < *indexOfLastItem; i++) {
    arr[i] = arr[i + 1];
  }
  *indexOfLastItem -= 1;
}

int main() {
  printIntro("Deleting item from given postion in array");

  int LA[10] = {23, 56, 8, 98, 5, 3, 687, 5};
  int indexOfLastItem = 7;

  printf("Array elements are : \n");
  for (size_t i = 0; i < indexOfLastItem; i++) printf("%d ", LA[i]);

  int position;
  printf("\nenter position item to be deleted from : ");
  scanf("%d", &position);
  deleteFromPosition(LA, position, &indexOfLastItem);

  for (size_t i = 0; i < indexOfLastItem; i++) printf("%d ", LA[i]);

  return 0;
}
