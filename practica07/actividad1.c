/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 7 - Actividad 1
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Cada nodo almacena un dato del stack
struct node{ 
    float dato; 
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
    tpila stack357;
    int i;
    //Crear una pila
    creaPila(&stack357);
    
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
    //No hay tope para la pila de tamaño 0
    stack->tope=NULL; 
    //El tamño inicial es 0
    stack->tam=0; 
}

int vacia(tpila *stack){
    //Condiciones de una pila vacia
    if(stack->tope==NULL && stack->tam==0) return 0; 
    else return 1; 
}

int push (tpila *stack, float dato){ 
    //Se crea un nuevo nodo para almacenar el dato a insertar
    nodo *nuevoNodo; 
    nuevoNodo = (nodo *)malloc(sizeof(nodo));
    
    //Se aborta la funcion si el nuevo nodo es nulo 
    if(nuevoNodo==NULL){ 
        return 1; 
    }
    
    //Se asigna el dato ingresado en push en el nuevo nodo
    nuevoNodo->dato=dato; 
    //Se fija el tope de la fila para que otro nodo pueda crearse
    nuevoNodo->sig=stack->tope; 
    stack->tope=nuevoNodo; 
    //Se incrementa en una unidad el tamaño de la pila
    stack->tam++; 
    return 0; 
}

float pop(tpila *stack){
    nodo *tmp; 
    float dato; 
    //Verificar que la pila no este vacia
    if(!vacia(stack)) return -1.0; 
    // El nodo temporal recibe el valor del ultimo nodo insertado
    tmp=stack->tope; 
    stack->tope=stack->tope->sig; 
    //Se disminuye en una unidad el tamaño del arreglo 
    stack->tam--; 
    //Se asigmna el campo dato a la variable a retornar.
    dato=tmp->dato; 
    free(tmp); 
    return dato; 
}

void mostrar( tpila *stack){
    nodo *tmp; 
    // Se asigna el nodo temporal para hacer las iteraciones
    tmp=stack->tope; 
    printf("\n");
    while(tmp!=NULL){
        //Imprime los valores de la pila
        printf("%f ",tmp->dato);
        //Pasa al siguiente nodo
        tmp=tmp->sig;
    }
    printf("\n");
}