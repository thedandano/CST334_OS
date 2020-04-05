#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];

int main() {
    int i;
    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&threads[i], NULL, go, &i);
    }
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
    }
    printf("Main thraed done.\n");
    return 0;
}

void *go(void *arg) {
    printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *) arg);
    return 0;
}