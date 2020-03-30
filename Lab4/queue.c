#include <stdint.h>
#include "node.h"

struct queue {
  struct node *front; // front node or head
  struct node *back;  // back node or tail
};

/**
 * Allocates new queue dynamically.
 *
 * @return pointer to the queue
 */
struct queue *queue_create() {
  struct queue* q = (struct queue*) malloc(sizeof(struct queue));
  q->front = q->back = NULL;
  return q;
}

/**
 * Inserts new node in queue after the last node.
 *
 * @param l pointer to the queue (non-NULL)
 * @param int data
 * returns a pointer to the newly added node
 */
struct node* enqueue(struct queue *q, int data) {
  // creates a new linked list node
  struct node* temp = node_create(data);

  if(q->back == NULL) {
    q->front = q->back = temp;
    return temp;
  }

  q->back->next = temp;
  q->back = temp;

  return NULL;
}


/**
 * Deletes the first snode of the queue.
 * @param l pointer to the queue (non-NULL)
 */
void dequeue(struct queue *q) {
  if (q->front == NULL){
    return;
  }
  struct node* temp = q->front;
  q->front = q->front->next;

  if(q->front == NULL){
    q->back = NULL;
  }
    free(temp);

}

/**
 * Inserts new node in queue before the first node.
 *
 * @param l pointer to the queue (non-NULL)
 * @param int data
 * returns a pointer to the newly added node
 */
struct node* queue_add_front(struct queue *q, int data);

/**
 * Returns the first snode with the given string.
 *
 * @param l pointer to the queue (non-NULL)
 * @parap int data
 * @return struct snode* or NULL if no match
 */
struct node* queue_find(struct queue *q, int data) {
  struct node* temp = q->front;
  while (temp != NULL) {
    if (data == temp->data) {
      return temp;
      //temp->data = data;
    }

    temp = temp->next;
  }

  return temp;


}

// /**
//  * Deallocate a queue and all snodes
//  * @param l pointer to the queue
//  */
void queue_destroy(struct queue *q) {
  struct node* curr = q->front;
  struct node* next;
  while(curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
    q->front = q->back = NULL;
  
}

/**
 * Traverse the queue and print the content of each node.
 * @param l pointer to the queue (non-NULL)
 */
void queue_traverse(struct queue *q) {
  int counter = 0;
  struct node* temp = q->front;
  while (temp != NULL) {
    //printf("%d %d\n",counter, temp->data);
    printf("%d - ", temp->data);
    counter++;
    temp = temp->next;
  }
  printf("\n");
}

/**
 * Returns the number of elements in the queue (nodes).
 * @param l pointer to the queue (non-NULL)
 */
uint32_t queue_length(struct queue *q) {
  int counter = 0;
  struct node* temp = q->front;
  while (temp != NULL) {
    temp = temp->next;
    counter++;
  }
  return counter;
}

/**
 * Deletes the first snode with the given string.
 * @param l pointer to the queue (non-NULL)
 * @param int int data
 */
void queue_delete(struct queue *q, int data);


struct node* queue_get_front(struct queue* q);

struct node* queue_get_back(struct queue* q);
