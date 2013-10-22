#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int glob = 6;

int main()
{
    int var;
    pid_t pid;

    var = 88;
    printf("Before fork.\n");

    if((pid = vfork()) < 0) {
        perror("vfork error");
        return -1;
    } else if (pid == 0) {
        glob++;
        var++;
        exit(0);
    }   
    
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    return 0;
}
