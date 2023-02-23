/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 1 - Actividad 6
*******************************************************************************/
#include <stdio.h>
#include <math.h>

#define MAXSIZE 10
int main(int argc, char const *argv[])
{
    int n, i, j, A[MAXSIZE][MAXSIZE];
    printf("n = ");
    scanf("%d", &n);
    for (i = 0; i <= n + 1; i++)
    {
        A[0][i] = i-1; //Fill up the first row: 0, 1, 2, 3, 4, ..., n
    }
    for (i = 0; i <= n + 1; i++)
    {
        A[i][0] = i-1; //Fill up the first column: 0, 1, 2, 3, 4, ..., n
    }
    for (i = 1; i <= n +1; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            A[i][j] = A[0][j] + A[i][0]; //add up each element from the first row with another one from the first column
        }
        
    }    

    for (i = 0; i <= n + 1; i++) //Print out the final result
    {
        for (j = 0; j <= n + 1; j++)
        {
            if(!i && !j) {
                printf("+  ");
                continue;
            }
            printf("%d  ", A[i][j]); 
        }
        printf("\n");
    }    
}

