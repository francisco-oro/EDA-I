/******************************************************************************
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 2 - Actividad 4
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define n 10
/* Prototipos de funciones */
void llena(int *n1);
void suma(int *n1, int *n2, int *sum);
void imprime(int *n1);

int main(int argc, char const *argv[])
{
    int A[n], B[n], C[n], *a, *b, *c;
    a=A;
    b=B;
    c=C;
    llena(a);
    llena(b);
    suma(a,b,c);

    imprime(a);
    imprime(b);
    imprime(c);
    return 0;
}

void llena(int *n1){
    int i;
    for (i = 0; i < n; i++)
    {
        *(n1+i)=rand()%n;  //Fill up the array with random numbers
    }
}

void suma(int *n1, int *n2, int *sum){
    int i;
    for (i = 0; i < n; i++)
    {
        *(sum+i)=*(n1+i)+*(n2+i);  //sum[i] = n1[i] + n[i]
    }   
}

void imprime(int *n1){
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(n1+i));  //printf("%d\t", n1[i])
    }
}