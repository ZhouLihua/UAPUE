#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int randint(int l, int u)
{
    int small = l <  u ? l : u;
    int big = l < u ? u : l;

    srand((unsigned) time(NULL));
    return small + rand() % (big - small);
}


int main()
{

    printf("%d,%d\n",randint(1,9),randint(9,1));
    return 0;
}
