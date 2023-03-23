/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 5 - Actividad 1
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

struct tipoPila
{
    int tope;
    int *stack;
    int n; 
};

typedef struct tipoPila pila;

void iniciaPila(pila *st, int size);
int llena(pila *st);
int vacia(pila *st);
void push(pila *st, int value);
int pop(pila *st);
void imprimePila(pila *st);
void liberaPila(pila *st);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

void iniciaPila(pila *st, int size){
    
}