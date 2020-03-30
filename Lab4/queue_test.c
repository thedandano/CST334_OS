#include <stdio.h>
#include "node.h"
#include "queue.h"


struct queue *q;
struct node *test;

int main(void)   {

    q = queue_create();
    //check lenght right after creation
    printf("Queue length after creation: %d\n", queue_length(q));

    enqueue(q, 99);
    enqueue(q, 201);
    enqueue(q, 1);
    enqueue(q, 22);
    enqueue(q, 33);
    enqueue(q, 69);
    enqueue(q, 21);
    enqueue(q, 2);
    
    //first part of the queue_find function
    test = queue_find(q,201);
    if (test != NULL)
      printf("queue_find Found this: %d\n\n",test->data);


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

    //second part of the queue_find function
    test = queue_find(q,201);
    if (test == NULL)
      printf("queue_find did not find 201\n\n");
 

    printf("Here are the top %d integers:\n", queue_length(q));
    printf("Content of the queue as follows.\n");
    queue_traverse(q);
    printf("Queue length right before Destruction: %d\n", queue_length(q));
    queue_destroy(q);
    //testing the length of the queue after it has been destroyed.
    printf("Queue length after destruction: %d\n", queue_length(q));
 

    return 0;
}
