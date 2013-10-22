#include <string.h>
#include <stdio.h>
#include <unistd.h>

int glob = 6;
char buf[] = "a write to stdout\n";

int main()
{
    int var;
    pid_t pid;

    var = 88;
    if(write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf)) {
        perror("write error");
        return -1;
    }

    printf("before fork.");

    if((pid = fork()) < 0){
        perror("fork error");
        return -2;
    }else if(pid == 0){
        glob++;
        var++;
    }else{
        sleep(2);
    }

    printf("pid = %d,glob = %d, var = %d\n", getpid(), glob, var);

    return 0;
}
