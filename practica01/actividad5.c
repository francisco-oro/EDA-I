/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 1 - Actividad 5
*******************************************************************************/
#include <stdio.h>
#include <math.h>
#define n 3

int main(int argc, char const *argv[])
{
    int A[n][n], j, i, prod = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(!i) A[i][j] = j + 1; 
            if(i==1) A[i][j] = 2;
            if(i==2) A[i][j] = fabs(-3 + j);
            if(i == j) prod *= A[i][j];
            printf("%d ", A[i][j]); 
        }
        printf("\n");
    }
    printf("Producto de la diagonal principal: %d", prod);
    return 0;
}
