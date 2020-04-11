/**
 * Name: Dan Sedano
 * Date 2020-11-04
 * Title: Lab 6 - Solving the consumer/producer problem.
 * Description: This program solves the consumer/producer problem using semaphors
 * for synchornization and locking.
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 

#define ALPHABET 26 
#define BUFFER_SIZE 1 // tested this with different sizes and it works beautifully!
// Threads
pthread_t producer_t;
pthread_t consumer_t;
// Semaphores
sem_t full, empty, mutex;
// Buffer variables
char buffer[BUFFER_SIZE];
int fill = 0;
int use = 0;

/**
 * Adds a character to the buffer
 * @param char value
 */
void put(char value) {
    buffer[fill] = value;
    fill = (fill + 1) % BUFFER_SIZE;
}

/**
 * Removes and returns a char from the buffer.
 * @return a char from the buffer.
 */ 
char get() {
    char temp = buffer[use];
    buffer[use] = ' ';
    use = (use + 1) % BUFFER_SIZE;
    return temp;
}

/**
 * Fills buffer with letters of the alphabet.
 */ 
void *producer() {
    char prodTemp = 'a';

     do{
        //produce next item
        sem_wait(&empty); // receives buffer empty signal
        sem_wait(&mutex); // aquires lock
        //add item to buffer
        put(prodTemp);

        // printf("->PUT: %c\n",prodTemp); // tracer
        // printf("buffer: [%s]\n",buffer); // tracer
        
        prodTemp++; // increments to the next letter in the alphabet
        sem_post(&mutex); // releases lock
        sem_post(&full); // sends buffer full signal
        
    }while(prodTemp <= 'z');

    return NULL;
}

/**
 * Removes letters from the buffer.
*/
void *consumer() {
    char temp;
    int counter = 0; //counter to break the loop
    
    do{
    
        sem_wait(&full); // receives buffer full signal
        sem_wait(&mutex); // aquires lock
        // remove next item from buffer
        temp = get();

        // printf("<-GET: %c\n",temp); //tracer
        // printf("buffer: [%s]\n",buffer); // tracer

        sem_post(&mutex); // releases lock
        sem_post(&empty); // sends buffer empty signal
        // consume the item
        printf("%c\n",temp);
        counter++;
    }while(counter < ALPHABET);
    return NULL;
}

int main() {
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFER_SIZE); // initialized to block producer when buffer is full
    sem_init(&mutex,0,1); //binary semaphore lock

    pthread_create(&producer_t, NULL, producer,NULL); // creates the producer thread
    pthread_create(&consumer_t, NULL, consumer,NULL); // creates the consumer thread

    // joins the threads
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