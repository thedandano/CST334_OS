/**
 *  Name: Dan Sedano
 *  Date: 2020-03-29
 *  Title: Lab 4 Fifo
 *  Description: This program simulates the FIFO algorithm for memory management.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <sys/queue.h>
//#include <limits.h>
#include "node.h"
#include "queue.h"


struct queue* q;
struct node* temp_page;

int main(int argc, char *argv[]){
    q = queue_create();// creates the queue
	  int C_SIZE = atoi(argv[1]); // Size of Cache passed by user

    char pageCache[100]; // Cache that holds the input from test file

    int line_counter = 0;
    int totalFaults = 0; // keeps track of the total page faults

    while (fgets(pageCache, 100, stdin)){

    	int page_num = atoi(pageCache); // Stores number read from file as an int
      line_counter++;

      //stores the result of queue_find
      temp_page = queue_find(q,page_num);
      if (temp_page == NULL) {
        totalFaults++;
        //printf("%d MiSS\n", line_counter);
        if(queue_length(q) < C_SIZE) { // if the queue size is less than the user input size
          enqueue(q, page_num);
        }
        else {
          dequeue(q);
          enqueue(q,page_num);
        }

      } //else {  printf("%d HIT\n", line_counter);}

    }

    printf("Total valid lines: %d\n", line_counter );
    printf("Total Faults: %d\n", totalFaults);
    double hitRate = (double) (line_counter-totalFaults)/line_counter*100;
    printf("Hit Rate: %.2f%%\n", hitRate);
    
    // free memory
    queue_destroy(q); 
    node_destroy(temp_page);

    return 0;

}
