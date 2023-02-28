/******************************************************************************
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 1 - Actividad 7 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int A[10][11], i, j, hist[10];
    for (i = 0; i < 10; i++)
    {
        hist[i] = 0; //LLenar histograma con ceros
    }
    
    for ( i = 0; i < 10; i++)
    {
        for (j = 0; j < 11; j++)
        {
            A[i][j] = (rand()%10);
            printf("%d ", A[i][j]); 
            hist[A[i][j]]++; //Incremento del histograma
        }
        printf("\n");
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d: %d\t", i, hist[i]); 
    }
    
    return 0;
}
