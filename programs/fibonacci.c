#include <stdio.h>

#include "intro.c"

int fib(int n) {
  if (n == 0 || n == 1) return n;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  printIntro("Topic");

  int n;
  printf("Enter lenght of fibonacci series : ");
  scanf("%d",&n) ;
  printf("Fibonacci series of %d terms : \n", n);
  for (int i = 0; i < n; i++) printf("%d ", fib(i));

  return 0;
}
