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

#define MAX_LOOPS 26
#define BUFFER_SIZE 1 // tested this with different sizes and it works beautifully!
pthread_t producer_t;
pthread_t consumer_t;
sem_t full, empty, mutex;

char buffer[BUFFER_SIZE];
int fill = 0;
int use = 0;

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % BUFFER_SIZE;
}

char get() {
    char temp = buffer[use];
    buffer[use] = ' ';
    use = (use + 1) % BUFFER_SIZE;
    return temp;
}


void *producer(void *arg) {
    char prodTemp = 'a';

     do{
        //produce next item
        sem_wait(&empty);
        sem_wait(&mutex);
        //add item to buffer
        put(prodTemp);
        printf("->PUT: %c\n",prodTemp); // tracer
        printf("buffer: [%s]\n",buffer); // tracer
        prodTemp++;
        sem_post(&mutex);
        sem_post(&full);
        
    }while(prodTemp <= 'z');

    return NULL;
}

void *consumer(void *arg) {
    char temp;
    int counter = 0;
    
    do{
    
        sem_wait(&full);
        sem_wait(&mutex);
        // remove next item from buffer
        temp = get();
        printf("<-GET: %c\n",temp); //tracer
        printf("buffer: [%s]\n",buffer); // tracer
        sem_post(&mutex);
        sem_post(&empty);
        // consume the item
        //printf("%c\n",temp);
        counter++;
    }while(counter < MAX_LOOPS);
    return NULL;
}

int main() {
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&mutex,0,1);

    pthread_create(&producer_t, NULL, producer,NULL);
    pthread_create(&consumer_t, NULL, consumer,NULL);

    pthread_join(producer_t,NULL);
    printf("Thread producer_t returned \n");
    pthread_join(consumer_t,NULL);
    printf("Thread consumer_t returned \n");

    printf("Main thread done.\n");
    //drop the semaphones when finished. 
    sem_destroy(&mutex); 
    sem_destroy(&full);
    sem_destroy(&empty);

}