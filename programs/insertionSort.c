#include <stdio.h>

#include "intro.c"

// Insertion Sort
void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  printIntro("implementation of Insertion Sort");

  int n;
  printf("enter the number of items in array : ");
  scanf("%d", &n);
  int arr[n];

  printf("enter items of array : ");
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  insertionSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
