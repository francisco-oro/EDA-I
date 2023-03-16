/******************************************************************************

Francisco Abimael Oro Estrada
Practica 4 - Problema 1

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

double *formaVect(int n);
void llenaVect(double *arr, int n);
void sumaElementos(double *arr1, double *arr2, double *arr3, int n);
void productoPunto(double *arr1, double *arr2, double *result);
void imprime(double *arr);

int main()
{
    unsigned int n;
    double *v1, *v2, *v3, res;
    printf("Introduce un valor de n: ");
    scanf("%d", &n);
    v1 = formaVect(n);
    v2 = formaVect(n);
    v3 = formaVect(n);
    if(v1==NULL || v2==NULL || v3==NULL){
        printf("Problemas al reservar la memoria\n");
        return(1);
    }
    llenaVect(v1, n);
    llenaVect(v2, n);
    sumaElementos(v1, v2, v3, n);
    productoPunto(v1, v2, &res);
    printf("\n Para los vectores:\n");
    imprime(v1);
    imprime(v2);
    printf("\nEl resultado de la suma es:\n");
    imprime(v3);
    printf("\nEl resultado del producto punto entre v1 y v2 es: %f", res);
    free(v1);
    free(v2);
    free(v3);
    return 0;
}

double *formaVect(int n){
    double *vec;
    vec = (double *)calloc(n+1, sizeof(double));
    vec[0] = n; 
    return vec; 
}

void llenaVect(double *arr, int n){
    int i=0;
    printf("Llenado del vector:\n");
    *(arr) = n; 
    for(i=1; i<=n; i++){
        printf("%d: ",i);
        scanf("%lf", (arr+i));
    }
}

void sumaElementos(double *arr1, double *arr2, double *arr3, int n){
    int i=0;
    for(i=1; i<=n; i++){
        *(arr3+i) = *(arr1+i) + *(arr2+i); 
    }
}
void productoPunto(double *arr1, double *arr2, double *result){
    int i=0, size;
    *result=0;
    size = arr1[0];
    for(i=1; i<=size; i++){
        *result += *(arr1+i) * *(arr2+i);
    }
}

void imprime(double *arr){
    int i=0,size;
    size = arr[0];
    for(i=1; i<=size; i++){
        printf("%f ", *(arr+i));
    }
    printf("Fin\n"); 
}


