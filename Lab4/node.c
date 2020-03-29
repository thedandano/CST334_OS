#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

/**
*
*
*
*/
struct node *node_create(int data) {
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

//NO CLUE IF THIS WILL WORK
/**
*
*
*
*/
void node_destroy(struct node * n) {

  if (n != NULL) { free(n); }
}


/**
*
*
*
*/
int node_get_data(struct node* n) {

  struct node *temp;
  for (temp = n; temp != NULL; temp = temp->next) {
    if (temp->data == n->data) {
      return temp->data;
    }
  }
  return 0;
}

/**
*
*
*
*/
struct node* node_get_next(struct node* n) {

  struct node *temp;
  temp = n->next;
  return temp;
}

/**
*
*/
