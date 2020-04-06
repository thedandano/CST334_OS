/**
 * Name: Dan Sedano
 * Date: 2020-06-04
 * Title: Lab 5 - Matrix Multiplcation
 * Description: This program multiplies a matrix by spliting up the work amongst mutiple threads.
 * It divides the work by createing one thread to compute each value of each row.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//constants
#define N 10
#define M 10
#define L 10
#define WIDTH 7 // holds the width for printf

//global matrix array variables
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

//struct to hold data
typedef struct thread_t {
   int threadnum;
} thread_t;

//
pthread_t threads[N];
thread_t *ptr[N];

// function prototypes
void *multiply(void *arg);
void printMatrix (double matrixTemp[][0], int xrows, int ycols);

/**
 * The main function for this program
 */
int main () {

    srand(time (NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrixA[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrixB[i][j] = rand() % 20;
        }
    }

    // Print A
    printf("Matrix A:\n");
    for (int rows = 0; rows < N; rows++) {
        for (int columns = 0; columns < M; columns++) {
            printf(" %-*.2f ", WIDTH , matrixA[rows][columns]);
        }
        printf("\n");
    }

    // Print B
    printf("\nMatrix B: \n");
    for (int rows = 0; rows < M; rows++) {
        for (int columns = 0; columns < L; columns++) {
            printf(" %-*.2f ", WIDTH, matrixB[rows][columns]);
        }
        printf("\n");
    }

////////////////////////////////////////////////////////////////////////////////////////////////
    // Create the Threads
    for (int i = 0; i < N; i++) {
        ptr[i] = malloc(sizeof(thread_t));
        ptr[i]->threadnum = i;

        // printf("Position %d\n", i);
        
        //create threads
        pthread_create(&threads[i],NULL,multiply,ptr[i]);
    }

    // Wait for threads
    for (int i = 0; i < N; i++) {
        //wait for threads here
        pthread_join(threads[i],NULL);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////

    //print C
    printf("\nMatrix C:\n");
    //printMatrix(matrixC,N,L);
    for (int rows = 0; rows < N; rows++) {
        for (int columns = 0; columns < L; columns++) {
            printf(" %-*.2f ", WIDTH, matrixC[rows][columns]);
        }
        printf("\n");
    }

    printf("Main Done\n");
    
    return 0;
}

/**
 * This function is used by each thread to compute the values of a matrix.
 * @param void *arg
 */
void *multiply (void *arg) {
    // holds the argument in a pointer
    thread_t *temp = (thread_t *) arg;
    //passes the arguments data into an int for usage provides the offset for the each thread
    int i = temp->threadnum;

    for (int j = 0; j < L; j++) {
        double temp = 0;
        for (int k = 0; k < M; k++) {
            temp += matrixA[i][k] * matrixB[k][j];
        }
        matrixC[i][j] = temp;
    }
    return 0;
}


/**
 * This function prints out each matrix.
 * @param double matrix[][], int xrows, int ycols
 */ 
void printMatrix (double matrixTemp[][0], int xrows, int ycols) {
    for (int x = 0; x < xrows; x++) {
        for ( int y = 0; y < ycols; y++) {
            printf(" %-*.2f ", WIDTH, matrixTemp[x][y]);
        }
        printf("\n");
    }

}