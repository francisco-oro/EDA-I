#include<stdlib.h>
#include<stdio.h>
/*Pilas y colas caracteres*/
/*  Karen Sáenz*/

struct node{
   char dato;
   struct node  *sig;
};

typedef struct node nodo;

struct tipoPila{
	nodo *tope;
	int tam;
	
};
typedef struct tipoPila tpila;

struct tipoCola{
	nodo *ini;
	nodo *fin;
	int tam;
	
};

typedef struct tipoCola tq;


void creaPila(tpila *stack);
int vaciap(tpila *stack);
char pop(tpila *stack);
void mostrarP( tpila *stack );

void creaCola(tq *q);
int vaciaQ(tq *q);
int encolar(tq *q, char dato);
char desencolar(tq *q);
void mostrarQ( tq *q );



void creaPila(tpila *stack){
    stack->tope=NULL;
    stack->tam=0;
    
}



int vaciaP(tpila *stack){
	if(stack->tope==NULL && stack->tam==0)
	   return 0;
	else
	    return 1;
	
}

int push (tpila *stack, char dato){
	 nodo *nuevoNodo;
	 nuevoNodo=(nodo *)malloc(sizeof(nodo));
	 if(nuevoNodo==NULL){
	 	return 1;
	 }  
	 nuevoNodo->dato=dato;
	 
	 nuevoNodo->sig=stack->tope;
	 stack->tope=nuevoNodo;
	 stack->tam++;
	 return 0;	
}


char pop(tpila *stack){
	nodo *tmp;
	char dato;
	if(!vaciaP(stack))
	    return -1.0;
	tmp=stack->tope;
	stack->tope=stack->tope->sig;
	stack->tam--;
	dato=tmp->dato;
	free(tmp);
	return  dato;
}

void mostrarP( tpila *stack ){
	nodo *tmp;
	tmp=stack->tope;
	while(tmp!=NULL){
		printf("%c ",tmp->dato);
		tmp=tmp->sig;
	}
	
}

void creaCola(tq *q){
    q->ini=NULL;
    q->fin=NULL;
    q->tam=0;   
	 
}

int vacia(tq *q){
	if(q->ini==NULL && q->fin==NULL && q->tam==0)
	   return 0;
	else
	    return 1;
	
}


//Se iserta al final
int encolar(tq *q, char dato){
	 nodo *nuevoNodo;
	 
	 nuevoNodo=(nodo *)malloc(sizeof(nodo));
	 if(nuevoNodo==NULL){
	 	return 1;
	 }  
	 nuevoNodo->dato=dato;
	 
	 nuevoNodo->sig=NULL;
	  
	 if( !vacia(q)){
        q->fin=nuevoNodo;
		q->ini=nuevoNodo;	
     }
     else{
     	q->fin->sig=nuevoNodo;
     	q->fin=nuevoNodo;
	 }
	 q->tam++;
	 return 0;	
}



char desencolar(tq *q){
	nodo *tmp;
	char dato;
	
	if(!vacia(q))
	    return 1;
	    
	tmp=q->ini;
	
	//hay u solo elemento
	if(q->ini==q->fin)
	  creaCola(q);
	
	else{
		q->ini=q->ini->sig;
	   q->tam--;	
	}
	 
	
	dato=tmp->dato;
	free(tmp);
	return  dato;
}



void mostrarQ( tq *q ){
	nodo *tmp;
	tmp=q->ini;
	while(tmp!=NULL){
		printf("%c ",tmp->dato);
		tmp=tmp->sig;
	}
	
}

