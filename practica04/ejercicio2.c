/******************************************************************************

Francisco Abimael Oro Estrada
Practica 4 - Problema 2

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

double **formaArreglo(int n, int m);
void sumaElementos(double **arr,int n,int m, double *res);
void liberarArreglo(double **arr, int n);

int main(){
    int n, m;
    double **mat, suma;
    printf("Introduce el valor de n: ");
    scanf("%d", &n);
    printf("Introduce el valor de m: ");
    scanf("%d", &m);
    mat = formaArreglo(n, m);
    sumaElementos(mat, n, m, &suma);
    printf("\n El resultado de la suma es %lf", suma);
    liberarArreglo(mat, n);
}

double **formaArreglo(int n, int m){
    double **arr; 
    int i, j;
    arr = (double **)calloc(n, sizeof(double));
    for(i=0; i<m; i++){
        arr[i] = (double *)calloc(m, sizeof(double));
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            arr[i][j]=2;
        }
    }
    return arr;
}

void sumaElementos(double **arr,int n,int m, double *res){
    int i, j;
    *res = 0; 
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            *res += *(*(arr + i)+j); 
        }
    }
}

void liberarArreglo(double **arr, int n){
    int i;
    for(i=0; i<n; i++){
        free(arr[i]); 
    }
    free(arr); 
}
