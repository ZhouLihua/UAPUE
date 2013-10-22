#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("%d,%d\n", getuid(), getgid());
    return 0;
}
