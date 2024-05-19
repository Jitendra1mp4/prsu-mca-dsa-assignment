#include <stdio.h>

#include "intro.c"

void search(int key, int arr[], int l) {
  for (int i = 0; i < l; i++) {
    if (key == arr[i]) {
      printf("found %d at %d index\n", key, i);
      return;
    }
  }
  printf("element not found\n");
}

int main() {
  printIntro("Linear search");

  int key, n;
  printf("enter number of element in array : ");
  scanf("%d", &n);
  int arr[n];
  printf("enter elements : \n");

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("all items are inserted!\n");
  printf("enter item to be searched : ");
  scanf("%d", &key);
  search(key, arr, n);
  return 0;
}
