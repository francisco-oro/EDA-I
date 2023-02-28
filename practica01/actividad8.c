/******************************************************************************
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 1 - Actividad 8
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 3
int main(int argc, char const *argv[])
{
    int A[MAXSIZE][MAXSIZE][MAXSIZE], i, j, k;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            A[2][i][j] = 0;   //Llenar la matriz producto con 0's
        }
        
    }
    
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                A[i][j][k] = (rand()%10);
                printf("%d ", A[i][j][k]);  //Lenar matrices 0 y 1 con números aleatorios
            }
            printf("\n");
        }
        printf("\n\n");
    }
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {   
            for (k = 0; k < 3; k++)
            {
                A[2][i][j] += (A[0][i][k] * A[1][k][j]);  //Multiplicación de matrices
                // printf("i: %d j: %d k: %d\n", i, j, k);
                // printf("%d * %d \n",A[0][i][k], A[1][k][i]);
            }
        }
    }
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", A[2][i][j]); //Imprime el producto de ambas matrices
        }
        printf("\n");
    }
    
}
