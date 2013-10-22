#include <stdio.h>

int days(void);
int main(int argc, char ** argv)
{
    printf("%d\n", days());
    return 0;
}

int days(void)
{
    int sum = 1;
    for(int i = 1; i < 32; i++)
        sum *= 2;
    return (sum -1) / (100 * 24 *60 *60);
}
