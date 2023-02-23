/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 1 - Actividad 4
*******************************************************************************/

#include <stdio.h>
#define MAXSIZE 10

int main(int argc, char const *argv[])
{
    int arr[3][3][3], i , j, k, totalSum = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                if(!i) { 
                    arr[i][j][k] = k + 1; //Matriz 0
                    if(j==k) totalSum += arr[i][j][k];
                } 
                if(i==1){
                    arr[i][j][k] = k + 2;  // Matriz 1
                    if(j==k) totalSum += arr[i][j][k];
                }
                if(i==2) {
                    arr[i][j][k] = k + 3;  //Matriz 2
                    if(j==k) totalSum += arr[i][j][k];
                }
            }
        }
    }
    printf("Suma de las diagonales principiles: %d", totalSum);
    return 0;
}
