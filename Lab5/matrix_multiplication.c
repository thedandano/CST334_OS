#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//constants
#define N 10
#define M 10
#define L 5
#define WIDTH 7

//global matrix array variables
double matrixA[N][M];// = {{5,6}, {2,4}};
double matrixB[M][L];// = {{1,3}, {7,9}};
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
void printMatrix (double matrixTemp[][10], int xrows, int ycols);

/**
 * 
 * 
 */
int main () {

    srand(time (NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrixA[i][j] = rand() % 10;
        }
    }

    //srand(time (NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrixB[i][j] = rand() % 20;
        }
    }

    // Print A
    printf("Matrix A:\n");
    for (int columns = 0; columns < N; columns++) {
        for (int rows = 0; rows < M; rows++) {
            printf(" %-*.2f ", WIDTH , matrixA[columns][rows]);
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
    //printMatrix(matrixC,N,L);
    printf("\nMatrix C:\n");
    for (int columns = 0; columns < N; columns++) {
        for (int rows = 0; rows < L; rows++) {
            printf(" %-*.2f ", WIDTH, matrixC[columns][rows]);
        }
        printf("\n");
    }

    printf("Main Done\n");
    
    return 0;
}

/**
 * 
 * 
 */
void *multiply (void *arg) {
    //printf("start of multiply\n");

    thread_t *temp = (thread_t *) arg;
    //printf("%d\n", temp->position);
    int position = temp->threadnum;

    for (int j = 0; j < L; j++) {
        double temp = 0;
        for (int k = 0; k < M; k++) {
            temp += matrixA[position][k] * matrixB[k][j];
            // printf("Matrix A: %f\n", matrixA[j][k]);
            // printf("Matrix B: %f\n", matrixB[k][j]);
            // printf("Temp is: %f \n\n", temp);
        }
        matrixC[position][j] = temp;
        //printf("Temp: %.2f\n", temp);
    }
    return 0;
}


/**
 * 
 * 
 */ 
void printMatrix (double matrixTemp[][10], int xrows, int ycols) {
    for (int x = 0; x < xrows; x++) {
        for ( int y = 0; y < ycols; y++) {
            printf(" %f ", matrixTemp[x][y]);
        }
        printf("\n");
    }

}