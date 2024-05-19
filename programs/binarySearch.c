#include <stdio.h>

#include "intro.c"
// *** there is problem in binary search algo
// larger item which are not in the list are shown to be at 
// at 9th index YOU HAVE to FIX it
int search(int *arr, int n, int key) {
  int start = 0, end = n, mid;
  while (start <= end) {
    mid = (start + end) / 2;
    int currentValue = arr[mid];
    if (currentValue == key)
      return mid;
    else if (currentValue < key)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}

int main() {
  printIntro("Linear search");

  int key;
  const int n = 9;
  int arr[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
  printf("The array is : ");
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("enter item to be searched : ");
  scanf("%d", &key);

  int res = search(arr, n-1, key);
  if (res == -1) {
    printf("element not found\n");
  } else {
    printf("element %d found at index %d\n", key, res);
  }
  return 0;
}

// int searchRecursivly(int *arr, int key, int start , int end){
// 	if (start >= end) return -1 ;
// 	int mid = ( start + end ) / 2 ;

// 	int currVlu = arr[mid] ;
// 	if (currVlu == key) return mid ;
// 	else if(currVlu < key )return searchRecursivly(arr,key,start+1,end) ;
// 	else return searchRecursivly(arr,key,start,end-1) ;
// }