#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};


/**
* Creates a link list node.
* @param int data
* @return a node called temp.
*/
struct node *node_create(int data) {
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}


/**
* Destorys a node by freeing it's memory.
* @param struct node* n
*/
void node_destroy(struct node * n) {

  free(n); 
  
}


/**
* Returns a node if found.
* @param struct node* n
* @return the data of a node
*/
int node_get_data(struct node* n) {

  struct node *temp;
  for (temp = n; temp != NULL; temp = temp->next) {
    if (temp->data == n->data) {
      return temp->data;
    }
  }
  return -1;
}

/**
* Returns the next node in the list.
* @param struct node* n
* @return the next node in the list.
*/
struct node* node_get_next(struct node* n) {

  struct node *temp;
  temp = n->next;
    return temp; // It'll return the next node or NULL if it's already the last node.
}

/**
*
*/
