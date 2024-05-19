#include <stdio.h>

#include "intro.c"

void bubbleSort(int arr[], int n) {
  for (size_t i = 0; i < n - 1; i++) {
    for (size_t j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // swap item
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int main() {
  printIntro("Bubble sort implementation");

  int n;
  printf("enter the number of items in array : ");
  scanf("%d", &n);
  int arr[n];
  
  printf("enter items of array : ");
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  bubbleSort(arr, n);
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
