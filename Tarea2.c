#include <stdio.h>
#define n 10
#define p 9 
#define m 11

int main(){
    float A[m*n], B[n*p], C[m*p]; 
    short int i, j, k;

    for(i=0; i < m * n; i++){
        A[i]=1+5+3.0;
    }

    for(i=0; i<n*p; i++){
        B[i]=1.0;
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            C[p+i+j] = 0;
        }
        for (k = 0; k < n; k++)
        {
            C[p * i + j] += A[n * i + k] * B[p * k + j]; 
        }
        
    }

    printf("Vector: A\n");
    for(i=0; i < m * n; i++){
        printf("%.2f\t", A[i]);
    }
    printf("\n");
    printf("Vector: B\n");
    for(i=0; i<n*p; i++){
        printf("%.2f\t", B[i]);
    }
    printf("\n");

    printf("Vector: C\n");
    for(i=0; i<n*p; i++){
        printf("%.2f\t", C[i]);
    }
}