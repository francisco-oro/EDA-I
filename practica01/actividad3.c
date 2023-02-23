/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 1 - Actividad 3
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define m 3
#define n 2

int main(){
    int x=1, A[m][n]={{1, 4}, {3,1}, {5, 6}}, i, j, xCount=0, colSum[n]={0,0}; 
    for(i=0; i<n; i++){
        for(j=0;j<m;j++){
            if(A[j][i] == x) xCount++;
            colSum[i] += A[j][i];
        }
    }
    printf("Apariciones de x: %d\n", xCount);
    printf("Suma de columnas: \n");
    for(i=0;i<n;i++){
        printf("%d :%d \t", i+1, colSum[i]);
    }
}