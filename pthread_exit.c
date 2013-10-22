#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * thr_fn1(void * arg)
{
    printf("thread 1 running.\n");
    pthread_exit((void *)1);
}

void * thr_fn2(void * arg)
{
    printf("thread 2 running.\n");
    return (void *)2;
}

int main()
{
    pthread_t tid1, tid2;
    int err;
    void * ret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if(err != 0)
    {
        printf("Can not create thread.\n");
        return -1;
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if(err != 0)
    {
        printf("Can not create thread.\n");
        return -3;
    }

    err = pthread_join(tid1, &ret);
    if(err != 0)
    {
        printf("Can not jion thread1.\n");
        return -2;
    }

    printf("Thread1 exit. %d\n", (int)ret);
    err = pthread_join(tid2, &ret);
    if(err != 0)
    {
        printf("Can not jion thread2.\n");
        return -4;
    }
    printf("Thread 2 exit. %d\n", (int)ret);

    return 0;
}

