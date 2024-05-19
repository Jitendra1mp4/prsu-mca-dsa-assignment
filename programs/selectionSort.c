#include <stdio.h>
#include "intro.c"

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    printIntro("implementation of Selection Sort");
 int n;
  printf("enter the number of items in array : ");
  scanf("%d", &n);
  int arr[n];
  
  printf("enter items of array : ");
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
