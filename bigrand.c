#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long bigrand()
{
    srand((unsigned) time(0));
    short ran = rand();
    long  nrand = (ran << 15) | ran;    

    return nrand;
}


int main()
{
   unsigned long m = bigrand();
    printf("%ld\n",m);
    
    return 0;
}
