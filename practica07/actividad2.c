/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 7 - Actividad 2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{ 
    char dato; 
    struct node *sig; 
};

typedef struct node nodo; 

struct tipoPila{ 
    nodo *tope; 
    int tam; 
}; 
    
typedef struct tipoPila tpila; 

void creaPila(tpila *stack);
int vacia(tpila *stack);
int push (tpila *stack, float dato);
float pop(tpila *stack);
void mostrar( tpila *stack);

int main(){
    tpila word;
    int i;
    //Crear una pila
    creaPila(&word);
    
    /*Insertar 4 elementos en la pila: 0.9, 1.8, 2.7, 3.6
    El orden de de los elementos sera: 3.600000 2.700000 1.800000 0.900000 */
    for(i=0;i<4;i++){
        push(&stack357, (i+1)*.9);
    }
    
    //Mostrar el contenido de la pila (los cuatro elementos insertados previamente)
    mostrar(&stack357); 
    
    //Elimina los elementos 3.6 y 2.7 de la pila
    for(i=0;i<2;i++){
        printf("%f ", pop(&stack357));
    }
    
    /*Mostrar el contenido de la pila
    (Solo quedan los dos primeros elementos que se insertaron)*/
    mostrar(&stack357);
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

int push (tpila *stack, float dato){ 
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
    float dato; 
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
        printf("%f ",tmp->dato);
        tmp=tmp->sig;
    }
    printf("\n");
}