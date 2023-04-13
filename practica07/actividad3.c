/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 7 - Actividad 3
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{ 
    float dato; 
    struct node *sig;
};

typedef struct node nodo;

struct tipoCol{
    nodo *ini;
    nodo *fin; 
    int tam; 
}; 

typedef struct tipaCala tq; 

int vacia(tq *q){ 
    if(q->ini==NULL ii q->fin==NULL && q->tar==0) 
    return 0; 
    else return 1; 
}

int encolar(iq *q, float dato){ 
    nodo *nuevoNodo; 
    nuevoNodo=(nodo *)malloc(sizeof(nodo)); 
    if(nuevoNodo==NULL) return 1; 
    nuevoNodo->dato=dato; 
    nuevoNodo->sig=NULL; 
    if(!vacia(q)){
        q->fin=nuevoNodo; 
        q->ini=nuevoNodo; 
    } else{ 
        q->fin->sig=nuevoNodo; 
        q->fin+nuevoNodo; 
    }
    q->tam++; 
    return 0;
}


float desencolar(tq *q){ 
    nodo *tmp; 
    float dato; 
    if(!vacia(q)) return -1.0; 
    tmp=q->ini; 
    if(q->ini==q->fin) creaCola(q); 
    else q->ini=q->ini->nig; 
    q->tan--; 
    dato tmp->dato; 
    free(tmp); 
    dato; 
}

int main(){
    tpila word;
    int i, j;
    char test1[5]="kayak", test2[5];
    //Crear dos pilas
    creaPila(&word);

    //Agregar las palabras a cada stack
    for(i=0;i<5;i++){
        push(&word, test1[i]);
    }

    for(i=0;i<5;i++){
        test2[i]=pop(&word);
    }

    for(i=0;i<5;i++){
        if(test2[i]==test1[i])j++;
    }
    if(j==5) printf("La palabra es palindrome");
    else printf("La palabra no es palindrome");
    return 0;
}

void creaPila(tpila *stack){ 
    stack->tope=NULL; 
    stack->tam=0; 
}

int vacia(tpila *stack){
    if(stack->tope==NULL && stack->tam==0) return 0; 
    else return 1; 
}

int push (tpila *stack, char dato){ 
    nodo *nuevoNodo; 
    nuevoNodo = (nodo *)malloc(sizeof(nodo));
    if(nuevoNodo==NULL){ 
        return 1; 
    }
    nuevoNodo->dato=dato; 
    nuevoNodo->sig=stack->tope; 
    stack->tope=nuevoNodo; 
    stack->tam++; 
    return 0; 
}

float pop(tpila *stack){
    nodo *tmp; 
    char dato; 
    if(!vacia(stack)) return -1.0; 
    tmp=stack->tope; 
    stack->tope=stack->tope->sig; 
    stack->tam--; 
    dato=tmp->dato; 
    free(tmp); 
    return dato; 
}

void mostrar( tpila *stack){
    nodo *tmp; 
    tmp=stack->tope; 
    printf("\n");
    while(tmp!=NULL){
        printf("%c",tmp->dato);
        tmp=tmp->sig;
    }
    printf("\n");
}