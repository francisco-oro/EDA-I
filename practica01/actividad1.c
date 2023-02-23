/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 1 - Actividad 1
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int main()

{
    int m, i, A[MAXSIZE], biggestOne;
    printf("m: ");
    scanf("%d", &m);
    for(i=0; i<m; i++){
        A[i]=(rand()%251);
        printf("%d\n", A[i]);
        if(!i) biggestOne = A[i];
        if(A[i] > biggestOne){
            biggestOne = A[i];
        }
    }
    printf("Biggest Value: %d", biggestOne);
}