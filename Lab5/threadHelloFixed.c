/**
 * Name: Dan Sedano
 * Date: 2020-06-04
 * Title: Lab 5 - Thread Hello Fixed
 * Description: This program applies a syncronization fix to the the Thread Hello program by
 * working with data in the heap rather than in the stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];

int main()
{
    int i;

    for (i = 0; i < NTHREADS; i++)
    {
        int *ptr = malloc(sizeof(int)); // creates a new variable to pass into each thread during each loop
        *ptr = i;
        pthread_create(&threads[i], NULL, go, ptr);
    }
    for (i = 0; i < NTHREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %d returned\n", i);
    }
    printf("Main thread done.\n");
    //free(ptr);
    return 0;
}

void *go(void *arg)
{
    printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);
    free(arg); // frees the pointer memory
    return 0;
}