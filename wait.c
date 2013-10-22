#include "pr_exit.h"
#include <unistd.h>

int main()
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("fork error");
        return -1;
    } else if (pid == 0) {
        exit(7);
    }

    if (wait(&status) != pid) {
        perror("wait error");
        return -2;
    }
    pr_exit(status);

    if ((pid = fork()) < 0) {
        perror("fork error");
        return -1;
    } else if (pid == 0) {
        abort();
    }

    if (wait(&status) != pid) {
        perror("wait error");
        return -2;
    }
    pr_exit(status);

    if ((pid = fork()) < 0) {
        perror("fork error");
        return -1;
    } else if (pid == 0) {
        status /= 0;
    }

    if (wait(&status) != pid) {
        perror("wait error");
        return -2;
    }
    pr_exit(status);

    return 0;
}
