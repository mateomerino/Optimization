#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <math.h>
#include <time.h>



// int XDIM = 100;
// int YDIM = 100;
#define XDIM 1000
#define YDIM 1000
#define SIZEPOINTER sizeof(double *)


// We return the pointer
double **alloc_matrix(void) /* Allocate the array */
{
    /* Check if allocation succeeded. (check for NULL pointer) */

    // int i;
    

    // int j, k; 

    register unsigned int i;

    double ** array = malloc(XDIM * SIZEPOINTER);

    for(i = 0 ; i < XDIM ; i++)
        array[i] = malloc((size_t)YDIM*SIZEPOINTER);


    return array;
}


void fill(double** arr) {
    /* fill the array with random values */

    // int i, j;
    register unsigned int i, j;

    // time_t t1; 

    // srand ( (unsigned) time (&t1));
    srand(1); 

    // for(i = 0 ; i < XDIM ; i++)
    //     for(j = 0 ; j < YDIM ; j++)
    //         arr[i][j] = (double)(rand() % 100);



    for(i = 0 ; i < XDIM ; i++)
        for(j = 0 ; j < YDIM ; j+=10){
            arr[i][j] = (double)(rand() % 100);
            arr[i][j+1] = (double)(rand() % 100);
            arr[i][j+2] = (double)(rand() % 100);
            arr[i][j+3] = (double)(rand() % 100);
            arr[i][j+4] = (double)(rand() % 100);
            arr[i][j+5] = (double)(rand() % 100);
            arr[i][j+6] = (double)(rand() % 100);
            arr[i][j+7] = (double)(rand() % 100);
            arr[i][j+8] = (double)(rand() % 100);
            arr[i][j+9] = (double)(rand() % 100);
        }

}

void compute(double** arr){
    /* Computes the kernell */
    // int kern[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
    __int8_t kern[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

    double tmp_sum[9];

    // double dato, accum;
    double accum = 0;
    int i, j; 
    // int k, l;    


    for (i = 0; i < XDIM ; i++)
        for (j = 0; j < YDIM ; j++){
            if(i>=1 && j>=1 && i< XDIM-1 && j<YDIM-1 ){

                tmp_sum[0] = kern[0][0] * arr[i - 1][j - 1] * 0.004 + 1;
                tmp_sum[1] = kern[0][1] * arr[i - 1][j] * 0.004 + 1;
                tmp_sum[2] = kern[0][2] * arr[i - 1][j + 1] * 0.004 + 1;
                tmp_sum[3] = kern[1][0] * arr[i][j - 1] * 0.004 + 1;
                tmp_sum[4] = kern[1][1] * arr[i][j] * 0.004 + 1;
                tmp_sum[5] = kern[1][2] * arr[i][j + 1] * 0.004 + 1;
                tmp_sum[6] = kern[2][0] * arr[i + 1][j - 1] * 0.004 + 1;
                tmp_sum[7] = kern[2][1] * arr[i + 1][j] * 0.004 + 1;
                tmp_sum[8] = kern[2][2] * arr[i + 1][j + 1] * 0.004 + 1;

                accum = tmp_sum[0] + tmp_sum[1] + tmp_sum[2] + tmp_sum[3] + tmp_sum[4] + tmp_sum[5] + tmp_sum[6] + tmp_sum[7] + tmp_sum[8];
            }
            arr[i][j] = accum;
        }

}


void print(double** arr) {
    /* Print the array */

    // int i, j;
    register unsigned int i, j;

    for(i = 0 ; i < XDIM ; i++)
        for(j = 0 ; j < YDIM ; j++)
            // printf("array[%d][%d] = %f\n", i, j, *(*(arr + i) + j));
            printf("array[%d][%d] = %f\n", i, j, arr[i][j]);

}

void free_matrix(double **array) /* Free the array */
{
    for (unsigned int i = 0; i < XDIM; i++)
        free(array[i]);

    free(array);
}


int main(void)
{
    // int i = 0;
    // double **arr;
    // int kern[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

    // arr = alloc_matrix();

  

    double **arr = alloc_matrix();

    fill(arr);

    compute(arr);
    // compute(arr, kern);

    // print(arr);

    free_matrix(arr);

    // free(arr);



    return 0;
}