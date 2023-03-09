/******************************************************************************
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 2 - Actividad 5
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int main(int argc, char const *argv[])
{
    int a[MAXSIZE][MAXSIZE], b[MAXSIZE][MAXSIZE], c[MAXSIZE][MAXSIZE], i, j;
    for (i = 0; i < MAXSIZE; i++)
    {
        for (j = 0; j < MAXSIZE; j++)
        {
            //Fill up the matrices a & b
            *(*(a+i)+j) = rand()%MAXSIZE;
            *(*(b+i)+j) = rand()%MAXSIZE;
            //Add up each term and store it in the matrix c
            *(*(c+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);

            //Display the results
            printf("%d \t", *(*(c+i)+j));
        }
        printf("\n");
    }
    
    return 0;
}
