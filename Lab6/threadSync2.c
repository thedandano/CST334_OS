/**
 * Name: Dan Sedano
 * Date 2020-10-04
 * Title: Lab 6 - Solving the consumer/producer problem.
 * Description: This program solves the consumer/producer problem using semaphors
 * for synchornization and locking.
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 

#define NTHREADS 26
#define MAX 1
pthread_t threads[NTHREADS];
sem_t full, empty, mutex;

char buffer[MAX];
int fill = 0;
int use = 0;
//char prodTemp = 'a';

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
}

char get() {
    char temp = buffer[use];
    use = (use + 1) % MAX;
    return temp;
}


void *producer(void *arg) {
    
    // do{
    for (char prodTemp = 'a'; prodTemp <='z'; prodTemp++) {
        //produce next item
        sem_wait(&empty);
        sem_wait(&mutex);
        //add item to buffer
        //printf("Before PUT %c\n",prodTemp);
        put(prodTemp);
        //printf("AFTER PUT %c\n",prodTemp);
        prodTemp++;
        //printf("%c\n",prodTemp);
        sem_post(&mutex);
        sem_post(&full);
        
    }  
    // }while(prodTemp == 'z');
    
    return NULL;
}

void *consumer(void *arg) {
    char temp;
    
    do{
        sem_wait(&full);
        sem_wait(&mutex);

        // remove next item from buffer
        temp = get();
        sem_post(&mutex);
        sem_post(&empty);

        // consume the item
        printf("Thread %p: %c\n", (void*)(size_t)arg,temp);

    }while(temp == 'z');
    
    return NULL;
}

int main() {
    sem_init(&full,0,0);
    sem_init(&empty,0,NTHREADS);
    sem_init(&mutex,0,1);

    static int i;

    // char c = 'a';
    // printf("%c\n",c);
    // c++;
    //  printf("%c\n",c);


    for (i = 0; i < NTHREADS; i++){
        pthread_create(&threads[i], NULL, producer, (void *)(size_t)i); //the last arg is the arg of go
        
    }  
        

    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&threads[i], NULL, consumer,(void *)(size_t)i);
    }
        

    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
        printf("Thread %d returned \n", i);
    }
    // pthread_create(&threads[0], NULL, producer, (void *)(size_t)i);
    // pthread_create(&threads[1], NULL, consumer,(void *)(size_t)i);
    // pthread_join(threads[0],NULL);
    // printf("Thread %d returned \n", 0);
    // pthread_join(threads[1],NULL);
    // printf("Thread %d returned \n", 1);

    printf("Main thread done.\n");
    sem_destroy(&mutex); //drop the semaphone when finished. 
    sem_destroy(&full);
    sem_destroy(&empty);

}