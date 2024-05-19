#include <stdio.h>

#include "intro.c"

long long fact(long long n) {
  if (n == 0 || n == 1) return 1;
  return n * fact(n - 1);
}

int main() {
  printIntro("Factorial using recursion");
  int num ;
  printf("Enter number to calculate factorial : " ) ;
  scanf("%d",&num) ;
  printf("factorial %d = %lld\n",num,fact(num)) ;
  return 0;
}
