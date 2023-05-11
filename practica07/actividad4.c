/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 7 - Actividad 4
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
typedef struct tipoCola c_queue; 

void startc_queue(c_queue *c_queue){
    // Los nodos a inicio y fin son nulos, mientras que el tamaño de la cola deberá ser de 0 elementos
    c_queue->fin = NULL;
    c_queue->ini = NULL;
    c_queue->tam = 0;
}

int vacia(c_queue *tq){
    // Regresa verdadero si la cola está vacía
    if (tq->ini == NULL && tq->fin == NULL && tq->tam == 0)
    {
        return 1; 
    } 
    // False if c_queue is empty
    else
    {
        return 0; 
    }
}

int enc_queue(c_queue *c_queue, float val){
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
    // If the c_queue is empty, assign the new node to its front and rear
    if (vacia(c_queue))
    {
        c_queue->fin = newNode;
        c_queue->ini = newNode;
    }
    // If the c_queue is not empty: 
    // (1) assign the new node as the next of the last node in the list 
    // (2) Update the new Node as the last item
    // (3) Assign the first node as the end of the new node
    else
    {
        c_queue->fin->sig = newNode;
        c_queue->fin = newNode;
        newNode->sig = c_queue -> ini; 
    }
    // Increase the size of the c_queue
    c_queue->tam++;
    return 0; 
}

float dec_queue(c_queue *c_queue){
    nodo *tmp;
    float returnValue;
    // Stop the function if the c_queue is empty
    if (vacia(c_queue))
    {
        printf("This c_queue is empty\n");
        return -1;
    }
    // Retrieve the first item in the c_queue and assign it to the temporary node
    tmp = c_queue->ini;
    // Restart the c_queue if there's only one item left in it before removing it
    if (c_queue->fin == c_queue ->fin && c_queue->tam == 1) 
    {
        startc_queue(c_queue);
    }
    // If there's more than one element in the c_queue 
    // (1) Update the second item as the new first item in the list 
    // (2) Decrease its size by 1 unit
    // (3) Update the new first item as the next item of the last one
    else
    {
        c_queue->ini = c_queue->ini->sig;
        c_queue->tam--;
        c_queue->fin->sig = c_queue->ini;
    }
    // Return the removed value and release the memory to the system
    returnValue = tmp->value;
    free(tmp);
    return returnValue;
}

void display(c_queue *c_queue){
    nodo *tmp;
    tmp = c_queue->ini;
    // Loop through the items in the c_queue
    for (size_t i = 0; i < c_queue->tam; i++)
    {
        printf("%f ", tmp->value);
        // Update the item as the next one
        tmp = tmp->sig;
    }   
    printf("\n");
}

int main(int argc, char const *argv[])
{
    c_queue c_queue1;
    
    startc_queue(&c_queue1);
    printf("Enqueue 6 elements : \n");
    for (size_t i = 0; i < 6; i++)
    {
        enc_queue(&c_queue1, i);
    }
    printf("Current queue : \n");
    display(&c_queue1);
    printf("----------------------------------"); 

    printf("\nDequeue 3 elements : \n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("Removed %.2f from the c_queue \n", dec_queue(&c_queue1));
    }
    printf("Current queue : \n");
    display(&c_queue1);
    printf("----------------------------------"); 

    printf("\nEnqueue 6 elements : \n");
    for (size_t i = 6; i < 12; i++)
    {
        enc_queue(&c_queue1, i); 
    }
    printf("Current queue : \n");
    display(&c_queue1);
    printf("----------------------------------"); 

    return 0;
}
