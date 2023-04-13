/******************************************************************************;
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 5 - Actividad 4
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct tipoPila
{
    int tope;
    char *stack;
    int n; 
};

typedef struct tipoPila pila;

struct tipoCola
{
    int ini, fin, n;
    char *arr;
};

typedef struct tipoCola queue;

void iniQ(queue *nq, int size);
int llenaQ(queue *nq);
int vaciaQ(queue *nq);
void encolar(queue *nq, char newValue);
void imprime(queue *nq);
char desencolar(queue *nq);

void iniciaPila(pila *st, int size);
int llenaS(pila *st);
int vaciaS(pila *st);
void push(pila *st, char value);
char pop(pila *st);
void imprimePila(pila *st);
void liberaPila(pila *st);

int valueinarray(char val, char *arr, int size);

int main(int argc, char const *argv[])
{
    queue cola1, cola2;
    pila stack; 
    char str[20], newValue; 
    char set1[10]={'a','b','c','d','f','g','h','i','j','k'}, set2[15]={'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char set3[10]={'A','B','C','D','F','G','H','I','J','K'}, set4[15]={'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i; 
    printf("Ingrese un string: ");
    scanf("%s", str);

    iniciaPila(&stack, 20);
    iniQ(&cola1, 20);
    iniQ(&cola2, 20);


    for (i = 0; i < 20; i++)
    {
        push(&stack, str[i]);
    }

    imprimePila(&stack);
    
    for (i = 0; i < 20; i++)
    {
        newValue = str[i];
        if((valueinarray(str[i], set1, 10) || valueinarray(str[i], set3, 10))){
            encolar(&cola1, newValue);
        }
        if ((valueinarray(str[i], set2, 15) || valueinarray(str[i], set4, 15)))
        {
            encolar(&cola2, newValue); 
        }
    }

    imprime(&cola1);
    imprime(&cola2);
    return 0;
}

void iniQ(queue *nq, int size){
    nq->n = size;
    nq->ini=0;
    nq->fin=0;
    nq->arr=(char *)calloc(size, sizeof(char));
}

// Funcion para averiguar si la cola esta llena
int llenaQ(queue *nq){
    if(nq->n == nq->fin){
        return 1; 
    } else {
        return 0;
    }
}

int vaciaQ(queue *nq){
    if(nq->ini == nq->fin){
        return 1;
    } else {
        return 0;
    }
}

void encolar(queue *nq, char newValue){
    if(!llenaQ(nq)){
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
        printf("%c", nq->arr[i]);
    }
    printf("\n");
}

char desencolar(queue *nq){
    char value;
    int i;
    if(!vaciaQ(nq)){
        value=nq->arr[nq->ini];
        for(i=0; i<nq->fin-1; i++){
            nq->arr[i]=nq->arr[i+1];
        }
        nq->fin--;
    }    
    else {
        return 'l';
    }       
}

void iniciaPila(pila *st, int size){
        st->tope=0;
        st->stack=(char *)calloc(size, sizeof(char));
        st->n=size;
}

int llenaS(pila *st){
    if(st->n==st->tope){
        return 1;
    } else {
        return 0;
    }
}

int vaciaS(pila *st){
    if(st->tope==0){
        return 1;
    } else {
        return 0;
    }
}


void push(pila *st, char value){
    if(!llenaS(st)){
        st->stack[st->tope++]=value;
    } else {
        printf("Overflow\n");
    }
}

char pop(pila *st){
    char removedValue;
    if(!vaciaS(st)){
        removedValue = st->stack[--st->tope];
        return removedValue;
    } else {
        return 'l';
    }
}

void liberaPila(pila *st){
    free(st->stack);
}


void imprimePila(pila *st){
    int i;
    if(!vaciaS(st)){
        for(i=0; i<st->tope; i++){
            printf("%c", st->stack[i]);
        }
    }
}

int valueinarray(char val, char *arr, int size)
{
    int i;
    for(int i = 0; i < size; i++)
    {
        if(*(arr+i) == val) return 1;
    }
    return 0;
}