/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 6 - Actividad 1
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct cQueue {
    int front;
    int rear;
    int size; 
    char *arr; 
};

typedef struct cQueue cQueue;

void startcQueue(cQueue *cq, int n);
int fullcQueue(cQueue *cq);
int emptycQueue (cQueue*cq);
void enQueue(cQueue *cq, char newValue);
char deQueue(cQueue *cq);
void displayQueue(cQueue *cq);

int main(int argc, char const *argv[])
{
    cQueue queue1, queue2;
    int i;
    char sampleString[10] = "HolaMundo";
    startcQueue(&queue1, 9);
    startcQueue(&queue2, 3);

    for (i = 0; i < 9; i++)
    {
        enQueue(&queue1, sampleString[i]); 
    }
    for (i = 0; i < 4; i++)
    {
        enQueue(&queue2, deQueue(&queue1));
    }
    
    displayQueue(&queue1);
    return 0;
}

void startcQueue(cQueue *cq, int n){
    cq->front=-1;
    cq->rear=-1;
    cq->size=n;
    cq->arr=(char *)calloc(n, sizeof(char));
}

int fullcQueue(cQueue *cq){
    if(cq->front == 0 && cq->rear == cq->size) return 1;
    return 0;
}

int emptycQueue (cQueue*cq){
    if(cq->front == -1 && cq->rear == -1) return 1;
    return 0;
}

void enQueue(cQueue *cq, char newValue){
    if(!fullcQueue(cq)){
        if(emptycQueue(cq)) {
            cq->front=0;
            cq->rear=0;
        }
        cq->arr[cq->rear++]=newValue;
    } else {
        printf("\nThis queue is full\n");
    }
}

char deQueue(cQueue *cq){
    char data =cq->arr[cq->front];
    if(!emptycQueue(cq)){
        cq->front=-1;
    } else {
        return '/';
    }
}

void displayQueue(cQueue *cq){
    int i;
    for (i = 0; i < cq->rear; i++)
    {
        printf("%c", cq->arr[i]);
    }
}