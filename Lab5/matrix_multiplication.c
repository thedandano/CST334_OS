#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 2
#define M 2
#define L 2

double matrixA[N][M] = {{5,6}, {2,4}};
double matrixB[M][L] = {{1,3}, {7,9}};
double matrixC[N][L];

typedef struct mystruct {
   int j;
   int k;
} mystruct;

pthread_t threads[N];

void *multiply(void *arg);
void printMatrix (double matrixTemp[][10], int xrows, int ycols);


int main () {
    // Print A
    printf("Matrix A:\n");
    for (int columns = 0; columns < N; columns++) {
        for (int rows = 0; rows < M; rows++) {
            printf(" %.2f ", matrixA[columns][rows]);
        }
        printf("\n");
    }

    // Print B
    printf("Matrix B: \n");
    for (int columns = 0; columns < M; columns++) {
        for (int rows = 0; rows < L; rows++) {
            printf(" %.2f ", matrixB[columns][rows]);
        }
        printf("\n");
    }

    // Create the Threads
    for (int i = 0; i < N; i++) {
        mystruct *test;// = malloc(sizeof(mystruct));
        //create threads
        pthread_create(&threads[i],NULL,multiply,&test);
    }
    // Wait for threads
    for (int i = 0; i < N; i++) {
        //wait for threads here
        pthread_join(threads[i],NULL);

    }

    //print C
    //printMatrix(matrixC,N,L);
    printf("Matrix C:\n");
    for (int columns = 0; columns < N; columns++) {
        for (int rows = 0; rows < L; rows++) {
            printf(" %.2f ", matrixC[columns][rows]);
        }
        printf("\n");
    }

    printf("Done\n");
    
    return 0;
}

void *multiply (void *arg) {

    //mystruct *a =  arg;

    //printf ("size of J: %d size of K: %d", a->j, a->k);
    
    for (int j = 0; j < L; j++) {
        double temp = 0;
        for (int k = 0; k < M; k++) {
            temp += matrixA[j][k] * matrixB[k][j];
            printf("Matrix A: %f\n", matrixA[j][k]);
            printf("Matrix B: %f\n", matrixB[k][j]);
            printf("Temp is: %f \n", temp);
            
        }
        matrixC[j][j] = temp;
        
    }
    return 0;
}

void printMatrix (double matrixTemp[][10], int xrows, int ycols) {
    for (int x = 0; x < xrows; x++) {
        for ( int y = 0; y < ycols; y++) {
            printf(" %f ", matrixTemp[x][y]);
        }
        printf("\n");
    }

}