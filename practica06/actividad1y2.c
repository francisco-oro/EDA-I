/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 6 - Actividad 1 y 2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct colaC{
    char *datos;
    int ini, fin, ne, n;
};


typedef struct colaC cQueue;
void startcQueue(cQueue *cq, int n);
int fullcQueue(cQueue *cq);
int emptycQueue (cQueue*cq);
void enQueue(cQueue *cq, char newValue);
char deQueue(cQueue *cq);
void displayQueue(cQueue *cq);
void freeQueue(cQueue *cq);

int main(int argc, char const *argv[]){
    cQueue queue1, queue2;
    int i;
    char sampleString[10] = "HolaMundo";
    char favBand[10] = "theStrokes";
    startcQueue(&queue1, 9);
    startcQueue(&queue2, 3);
    for (i = 0; i < 9; i++)
    {
        enQueue(&queue1, sampleString[i]); 
    }
    displayQueue(&queue1);
    // Eliminamos los 4 primeros elementos de queue1 y los insertamnos en queue2
    for (i = 0; i < 4; i++)
    {
        enQueue(&queue2, deQueue(&queue1)); 
    }
    /* Como estamos agregando 4 elementos en una pila que puede almacenar como maximo 3, 
    Se imprime una advertencia de que la cola se encuentra llena */
    displayQueue(&queue1);
    displayQueue(&queue2);

    /* Advertencia de cola llena despues de la cuarta iteracion. No se pueden agregar 5 elementos
    porque solo hay 4 espacios disponibles. */
    for (i = 0; i < 5; i++)
    {
        enQueue(&queue1, favBand[i]); 
    }

    /* Muestra una diagonal despues de la tercera iteracion. No es posible eliminar 4 elementos porque
    solo hay 3 en la cola */
    for (i = 0; i < 4; i++)
    {
        printf("Valor eliminado: %c\n", deQueue(&queue2));
    }

    displayQueue(&queue1);
    displayQueue(&queue2);

    freeQueue(&queue1);
    freeQueue(&queue2);
    return 0;
}

void startcQueue(cQueue *cq, int n){
    cq->ini=0;
    cq->fin=0;
    cq->ne=0;
    cq->n = n;
    cq->datos=(char *)calloc(n, sizeof(char));
}

int fullcQueue(cQueue *cq){
    if(cq->ini == cq->fin && cq->ne==cq->n) return 1;
    else return 0;
}

int emptycQueue (cQueue*cq){
    if(cq->ini == cq->fin && cq->ne==0) return 1;
    return 0;
}

void enQueue(cQueue *cq, char newValue){
    if(!fullcQueue(cq)){
        cq->datos[cq->fin]=newValue;
        cq->ne++;
        cq->fin = (cq->fin+1)%cq->n; 
    } else {
        printf("\nThis queue is full\n");
    }
}

char deQueue(cQueue *cq){
    char data;
    if(!emptycQueue(cq)){
        data = cq->datos[cq->ini];
        cq->ini=(cq->ini+1)%cq->n;
        cq->ne--;
        return data;
    } else {
        printf("This queue is empty");
        return '/';
    }
}

void displayQueue(cQueue *cq){
    int i, index;
    index = cq->ini;
    printf("\n");
    for (i = cq->ini; i < cq->ne; i++)
    {
        printf("%c", cq->datos[index]);
        index=(index+1)%cq->n;
    }
    printf("\n");
}

void freeQueue(cQueue *cq){
    free(cq->datos);
}