#include <stdio.h>
#include "intro.c" 

void tower(int n , char from , char to , char aux){
   if (n == 1){
    printf("%c -> %c\n",from , to) ;
    return;
   }
   tower(n-1,from,aux,to);
   printf("%c -> %c\n",from , to) ;
   tower(n-1,aux,to,from) ;
}


int main(int argc, char const *argv[])
{
    printIntro("Tower of hanoi") ;
    int n ;
    tower(3,'A','B','Z') ;
    return 0;
}
