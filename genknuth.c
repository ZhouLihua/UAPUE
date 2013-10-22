#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void genknuth(int m, int n)
{
    srand((unsigned int) time(0));
    for(int i=0; i < n; i++)
    {
        if(rand() %(n-i) < m)
        {
            printf("%d\n",i);
            m--;
        }
    }
}


int main()
{
    genknuth(10,1000);
    return 0;
}
