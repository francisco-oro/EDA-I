/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 1 - Actividad 2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 40

float dotProduct(float u[MAXSIZE], float v[MAXSIZE]){
    int i;
    float result = 0; 
    for(i=0;i<MAXSIZE; i++){
        result += u[i] * v[i]; 
    }
    return result; 
}

void arraySum(float u[MAXSIZE], float v[MAXSIZE], float sum[MAXSIZE]){
    int i; 
    for(i=0;i<MAXSIZE; i++){
        sum[i] = u[i] + v[i]; 
    }
}

int main()
{
    int i;
    float u[MAXSIZE], v[MAXSIZE], sum[MAXSIZE], dP;
    for(i=0; i < MAXSIZE; i++){ 
        u[i] = 1;
        v[i] = 2;
        dP += u[i] * v[i];
    }
    arraySum(u, v, sum);
    printf("Producto punto: %.2f\n", dP); 
    printf("Suma de vectores \n"); 
    for(i=0; i<MAXSIZE; i++){
        printf("%.2f \t", sum[i]);
    }
}