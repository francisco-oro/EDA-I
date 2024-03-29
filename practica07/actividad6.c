/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 7 - Actividad 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    float value;
    struct node *sig; 
};

typedef struct node nodo;

struct tipoCola
{
    nodo *ini, *fin;
    int tam; 
};
typedef struct tipoCola queue; 

void startqueue(queue *queue){
    // Los nodos a inicio y fin son nulos, mientras que el tamaño de la cola deberá ser de 0 elementos
    queue->fin = NULL;
    queue->ini = NULL;
    queue->tam = 0;
}

int vacia(queue *tq){
    // Regresa verdadero si la cola está vacía
    if (tq->ini == NULL && tq->fin == NULL && tq->tam == 0)
    {
        return 1; 
    } 
    // False if queue is empty
    else
    {
        return 0; 
    }
}

int enqueue(queue *queue, float val){
    nodo *newNode;
    newNode = (nodo *)malloc(sizeof(nodo));
    // Stop the function if memory allocation fails
    if (newNode == NULL)
    {
        return 1; 
    }
    // Assign the value to the new node and set its next element as NULL
    newNode->value = val;
    newNode->sig = NULL;
    // If the queue is empty, assign the new node to its front and rear
    if (vacia(queue))
    {
        queue->fin = newNode;
        queue->ini = newNode;
    }
    // If the queue is not empty: 
    // (1) assign the new node as the next of the last node in the list 
    // (2) Update the new Node as the last item
    else
    {
        queue->fin->sig = newNode;
        queue->fin = newNode;
    }
    // Increase the size of the queue
    queue->tam++;
    return 0; 
}

float dequeue(queue *queue){
    nodo *tmp;
    float returnValue;
    // Stop the function if the queue is empty
    if (vacia(queue))
    {
        printf("This queue is empty\n");
        return -1;
    }
    // Retrieve the first item in the queue and assign it to the temporary node
    tmp = queue->ini;
    // Restart the queue if there's only one item left in it before removing it
    if (queue->fin == queue ->fin && queue->tam == 1) 
    {
        startqueue(queue);
    }
    // If there's more than one element in the queue 
    // (1) Update the second item as the new first item in the list 
    // (2) Decrease its size by 1 unit
    else
    {
        queue->ini = queue->ini->sig;
        queue->tam--;
    }
    // Return the removed value and release the memory to the system
    returnValue = tmp->value;
    free(tmp);
    return returnValue;
}

void display(queue *queue){
    nodo *tmp;
    tmp = queue->ini;

    // Loop through the items in the queue
    for (size_t i = 0; i < queue->tam; i++)
    {
        printf("%f ", tmp->value);
        // Update the item as the next one
        tmp = tmp->sig;
    }   
    printf("\n");
}

int enqueueAfter(queue *queue, float value, int index){
    nodo *tmp, *newNode;
    if (vacia(queue))
    {
        enqueue(queue, value);
        return 1;
    }
    else if (index < 0 || index >= queue->tam)
    {
        printf("Invalid index \n");
        return 0;
    }
    else if (index == queue->tam - 1)
    {
        enqueue(queue, value);
        return 1;
    }
    else
    {
        tmp = queue->ini;
        newNode = (nodo *)malloc(sizeof(nodo)); 
        newNode->value = value;
        for (size_t i = 0; i < index; i++)
        {
            tmp=tmp->sig;
        }
        newNode->sig = tmp->sig;
        tmp->sig = newNode; 
    }
    free(tmp);
    queue->tam++; 
}

int deleteAfter(queue *queue, int index){
    nodo *tmp, *newNode;
    if (vacia(queue))
    {
        printf("This queue is empty \n"); 
        return 0;
    }
    else if (index < 0 || index >= queue->tam)
    {
        printf("Invalid index \n");
        return 0;
    }
    else if (index == queue->tam-1)
    {
        printf("Nothing to delete here. This is the last element already.\n");
    }
    else
    {
        tmp = queue->ini;
        for (size_t i = 0; i < index-1; i++)
        {
            tmp=tmp->sig;
        }
        tmp->sig = tmp->sig->sig;
    }
    queue->tam--;
    free(tmp->sig);
}

int main(int argc, char const *argv[])
{
    queue queue1;
    
    startqueue(&queue1);
    printf("Enqueue 6 elements : \n");
    for (size_t i = 0; i < 6; i++)
    {
        enqueue(&queue1, i);
    }
    printf("Current queue : \n");
    display(&queue1);
    printf("----------------------------------"); 

    printf("\nDequeue elements after position (2): \n");
    deleteAfter(&queue1, 2);
    printf("Current queue : \n");
    display(&queue1);
    printf("----------------------------------"); 

    printf("\nEnqueue 4.3 after position (3) : \n");
    enqueueAfter(&queue1, 4.3, 3);
    printf("Current queue : \n");
    display(&queue1);
    printf("----------------------------------"); 

    return 0;
}
