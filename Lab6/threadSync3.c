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
#define BUFFER_SIZE 1
pthread_t producer_t[NTHREADS];
pthread_t consumer_t[NTHREADS];
sem_t full, empty, mutex;

char buffer[BUFFER_SIZE];
int fill = 0;
int use = 0;
char prodTemp = 'a';

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % BUFFER_SIZE;
    //printf("Fill: %d\n", fill); // tracer*
    
}

char get() {
    char temp = buffer[use];
    buffer[use] = '\0';
    use = (use + 1) % BUFFER_SIZE;
    return temp;
}


void *producer(void *arg) {
    
 
    sem_wait(&empty);
    sem_wait(&mutex);
    //add item to buffer
    //printf("Before PUT %c\n",prodTemp);
    put(prodTemp);
    //printf("AFTER PUT %c\n",prodTemp); // tracer*
    
    prodTemp++;
    sem_post(&mutex);
    sem_post(&full);
    //printf("buffer: %s\n",buffer); // tracer*
    return NULL;
}

void *consumer(void *arg) {
    char temp;

    sem_wait(&full);
    sem_wait(&mutex);
    // remove next item from buffer
    temp = get();
    //printf("AFTER GET: %c\n",temp); // tracer*
   
    sem_post(&mutex);
    sem_post(&empty);
    // consume the item
    printf("Thread %p: %c\n", (void*)(size_t)arg,temp); // Tracer
    //printf("buffer: %s\n",buffer); // tracer*
    //printf("%c\n",temp);
    return NULL;
}

int main() {
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&mutex,0,1);

    static int i;



    for (i = 0; i < NTHREADS; i++){
        pthread_create(&producer_t[i], NULL, producer, (void *)(size_t)i); //the last arg is the arg of go
        
        
    }  
        

    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&consumer_t[i], NULL, consumer,(void *)(size_t)i);
    }
        

    for (i = 0; i < NTHREADS; i++) {
        pthread_join(producer_t[i],NULL);
        printf("Producer thread %d returned \n", i);
    }
     for (i = 0; i < NTHREADS; i++) {
        pthread_join(consumer_t[i],NULL);
        printf("Consumer thread %d returned \n", i);
    }
  

    printf("Main thread done.\n");
    sem_destroy(&mutex); //drop the semaphone when finished. 
    sem_destroy(&full);
    sem_destroy(&empty);

}