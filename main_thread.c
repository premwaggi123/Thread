#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread1_function(void* arg)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Thread 1 running: %d\n", i);
        sleep(1);
    }

    return NULL;
}

void* thread2_function(void* arg)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Thread 2 running: %d\n", i);
        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1_function, NULL);
    pthread_create(&t2, NULL, thread2_function, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
