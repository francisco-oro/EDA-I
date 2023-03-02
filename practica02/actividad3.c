/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 2 - Actividad 3
*******************************************************************************/

#include <stdio.h>
#define n 10 
/*Prototipos de Funciones*/

void llenar(float *vp);
void imprimir(float *vp);
void sumaElementos(float *vp, float *sep);
void buscaMin(float *vp, float *mvp);
void promedio(float *vp, float *mp);

int main(int argc, char const *argv[])
{

    float a[n], resSuma, min, resProm, *ap;
    int i;
    ap = &a[0];
    llenar(a); 
    imprimir(a);
    sumaElementos(a, &resSuma);
    printf("Suma: %f\n", resSuma);
    buscaMin(a, &min);
    printf("Minimo: %f\n", min);
    promedio(a, &resProm);
    printf("Promedio: %f\n", resProm);
    return 0;     
}

/*Definiciones de Funciones*/

void llenar(float *vp){
    int i; 
    printf("Llenado del vector:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", (vp + i));
    }
}

void imprimir(float *vp){
    int i; 
    printf("Impresion del vector:\n");
    for (i = 0; i < n; i++)
    {
        printf("%f \t", *(vp + i));
    }
    printf("\n");
}

void sumaElementos(float *vp, float *sep){
    int i; 
    for (i = 0; i < n; i++)
    {
        *sep += *(vp + i);
    }
}

void buscaMin(float *vp, float *mvp){
    int i = 0;
    *mvp = *vp;
    for (i = 1; i < n; i++)
    {
        if(*(vp + i) < *mvp) *mvp = *(vp + i); 
    }   
}

void promedio(float *vp, float *mp){
    int i;
    float sum = 0; 
    for (i = 0; i < n; i++)
    {
        sum += *(vp + i);
    }
    *mp = (sum / n);  
}