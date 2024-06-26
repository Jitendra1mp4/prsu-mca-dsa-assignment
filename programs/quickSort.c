#include <stdio.h>

#include "intro.c"

// Quick Sort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  printIntro("implementation of Quick Sort");

  int n;
  printf("enter the number of items in array : ");
  scanf("%d", &n);
  int arr[n];

  printf("enter items of array : ");
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  quickSort(arr, 0, n - 1);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
