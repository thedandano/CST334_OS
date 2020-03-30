/**
 *  Name: Dan Sedano
 *  Date: 2020-03-29
 *  Title: Lab 4 queue_test
 *  Description: This file is a tester file to ensure queue and node were implemented correctly.
 *  The file was provided by Prof. Lamble. I made some modifications to test additional functions.
*/

#include <stdio.h>
#include "node.h"
#include "queue.h"


struct queue *q;
struct node *test;

int main(void)   {

    q = queue_create();

    printf("Queue length after creation: %d\n", queue_length(q));

    enqueue(q, 99);
    enqueue(q, 201);
    enqueue(q, 1);
    enqueue(q, 22);
    enqueue(q, 33);
    enqueue(q, 69);
    enqueue(q, 21);
    enqueue(q, 2);

    test = queue_find(q,201);
    if (test != NULL)
      printf("Found this: %d\n",test->data);


    printf("Here are the top %d integers:\n", queue_length(q));
    printf("Content of the queue as follows.\n");
    queue_traverse(q);

    printf("\n");
    printf("Dequeue the first 4\n");
    printf("\n");

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    test = queue_find(q,201);
    if (test == NULL)
      printf("not found\n");
    // if (test != NULL)
    //   printf("AFTER DEQUEUE Found this: %d\n",test->data);
    // else
    //   printf("not found\n");

    printf("Here are the top %d integers:\n", queue_length(q));
    printf("Content of the queue as follows.\n");
    queue_traverse(q);
    printf("Queue length right before Destruction: %d\n", queue_length(q));
    queue_destroy(q);
    //printf("Queue length after destruction: %d\n", queue_length(q));
  //  queue_traverse(q);

    return 0;
}
