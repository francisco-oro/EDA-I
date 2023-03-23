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
    pila pila1, pila2;
    int i,j;
    //Fill up the declared stacks
    iniciaPila(&pila1, 5);
    iniciaPila(&pila2, 4);

    printf("Push 5 elements to the first stack\n");
    for(i=0; i<5; i++){
        push(&pila1, i+1);
    }  
    imprimePila(&pila1);
    printf("\nPush 3 elements to the second stack\n");
    for(i=0; i<3; i++){
        push(&pila2, i+2);
    }
    imprimePila(&pila2);
    printf("\nPop 2 elements from the first stack\n");
    for(i=0; i<2; i++){
        printf("%d ", pop(&pila1));
    }
    printf("\nPop 4 elements from the first stack\n");
    for(i=0; i<4; i++){
        printf("%d ", pop(&pila1));
    }
    printf("\nDisplay stack 1\n");
    imprimePila(&pila1);
    printf("\nPop 2 elements from the second stack\n");
    for(i=0; i<2; i++){
        printf("%d ", pop(&pila2));
    }
    printf("\nDisplay stack 2\n");
    imprimePila(&pila2);
    return 0;
}

void iniciaPila(pila *st, int size){
        st->tope=0;
        st->stack=(int *)calloc(size, sizeof(int));
        st->n=size;
}

int llena(pila *st){
    if(st->n==st->tope){
        return 1;
    } else {
        return 0;
    }
}

int vacia(pila *st){
    if(st->tope==0){
        return 1;
    } else {
        return 0;
    }
}


void push(pila *st, int value){
    if(!llena(st)){
        st->stack[st->tope++]=value;
    } else {
        printf("Overflow\n");
    }
}

int pop(pila *st){
    int removedValue;
    if(!vacia(st)){
        removedValue = st->stack[--st->tope];
        return removedValue;
    } else {
        return -1;
    }
}

void liberaPila(pila *st){
    free(st->stack);
}


void imprimePila(pila *st){
    int i;
    if(!vacia(st)){
        for(i=0; i<st->tope; i++){
            printf("%d ", st->stack[i]);
        }
    }
}
