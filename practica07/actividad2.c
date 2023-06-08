/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 7 - Actividad 2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int push (tpila *stack, char dato);
float pop(tpila *stack);
void mostrar( tpila *stack);

int main(){
    tpila word, word2;
    int i, j, k;
    char test1[5]="kayak", test2[5]="tacos", output1[5], output2[5];

    //Crear dos pilas
    creaPila(&word);
    creaPila(&word2);
    //Agregar las palabras a cada stack
    for(i=0;i<5;i++){
        push(&word, test1[i]);
        push(&word2, test2[i]);
    }

    for(i=0;i<5;i++){
        output1[i]=pop(&word);
        output2[i]=pop(&word2);
    }

    for(i=0;i<5;i++){
        if(output1[i]==test1[i])j++;
        if(output2[i] == test2[i])k++;
    }
    if(j==5) printf("La palabra %s es palindrome \n", test1);
    else printf("La palabra %s no es palindrome \n", test1);
    if(k==5) printf("La palabra tacos es palindrome\n");
    else printf("La palabra tacos no es palindrome\n");
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