#include <stdio.h>
#include <stdlib.h>
#include "intro.c"

typedef struct node node ;

struct node
{
    int info ; 
    node *left ;
    node *right ;
};
