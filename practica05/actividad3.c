/******************************************************************************;
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 5 - Actividad 3
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct tipoCola
{
    int ini, fin, n;
    float *arr;
};

typedef struct tipoCola queue;

void iniQ(queue *nq, int size);
int llena(queue *nq);
int vacia(queue *nq);
void encolar(queue *nq, float newValue);
void imprime(queue *nq);
float desencolar(queue *nq);

int main(int argc, char const *argv[])
{
    queue cola1, cola2;
    float dato;
    iniQ(&cola1, 4);
    iniQ(&cola2, 8); 
    encolar(&cola1, 34);
    encolar(&cola1, 33);
    encolar(&cola1, 35);
    encolar(&cola1, 36);
    encolar(&cola1, 3);
    imprime(&cola1);

    dato=desencolar(&cola1);
    printf("%f \n", dato);

    dato=desencolar(&cola1);
    printf("%f \n", dato);

    imprime(&cola1);
    return 0;
}

void iniQ(queue *nq, int size){
    nq->n = size;
    nq->ini=0;
    nq->fin=0;
    nq->arr=(float *)calloc(size, sizeof(float));
}

// Funcion para averiguar si la cola esta llena
int llena(queue *nq){
    if(nq->n == nq->fin){
        return 1; 
    } else {
        return 0;
    }
}

int vacia(queue *nq){
    if(nq->ini == nq->fin){
        return 1;
    } else {
        return 0;
    }
}

void encolar(queue *nq, float newValue){
    if(!llena(nq)){
            nq->arr[nq->fin++]=newValue;
    } else {
        printf("\nLlena\n");
    }
}

void imprime(queue *nq){
    int i; 
    printf("\n");
    for (i = 0; i <= nq->fin-1; i++)
    {
        printf("%f\t", nq->arr[i]);
    }
}

float desencolar(queue *nq){
    float value;
    int i;
    if(!vacia(nq)){
        value=nq->arr[nq->ini];
        for(i=0; i<nq->fin-1; i++){
            nq->arr[i]=nq->arr[i+1];
        }
        nq->fin--;
        return value;
    }    
    else {
        return -99;
    }       
}





