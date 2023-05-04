/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 8 - Actividad 3
*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>


struct NodoLista{
      char dato;
      struct NodoLista *siguiente;
      struct NodoLista *anterior;
};


typedef  struct NodoLista nodo;
struct controlLista{
nodo *inicio;  
nodo *fin;
int numElem;
};

typedef struct controlLista Lista;


void inicializacion(Lista *lista){
   lista->inicio = NULL;
   lista->fin = NULL;
   lista->numElem = 0;
}

int vacia(Lista *lis){
	if(lis->inicio==NULL && lis->fin==NULL && lis->numElem==0)
	   return 1;
	else
	    return 0;
}

nodo *creaNodo(double dato){
	nodo  *nuevoNodo;
    nuevoNodo=(nodo *)malloc(sizeof(nodo));
     if(nuevoNodo!=NULL){
      nuevoNodo->dato=dato;
      nuevoNodo->siguiente=NULL;
      nuevoNodo->anterior=NULL;
     }
    return nuevoNodo;
	
}


int insertarInicio (Lista *lis, double dato){
	 nodo *nuevoNodo;
	 
	 nuevoNodo=creaNodo(dato);
	 if(nuevoNodo==NULL){
	 	return 1;
	 }  

    if( vacia(lis)){
        lis->fin=nuevoNodo;
		lis->inicio=nuevoNodo;		
        nuevoNodo->anterior=NULL;
    }
     else{
            // Asignar el siguiente del nuevo nodo y dejar como nulo el campo del nodo anterior
           nuevoNodo->siguiente=lis->inicio;
	       lis->inicio=nuevoNodo;
           nuevoNodo->siguiente->anterior=nuevoNodo;
           nuevoNodo->anterior= NULL;
	 }
     
     lis->numElem++;
     return 0;
}   


int  insertarFinal(Lista *lis, char dato){
      nodo *nuevoNodo;
	 
	 nuevoNodo=creaNodo(dato);
	 if(nuevoNodo==NULL){
	 	return 1;
	 }  
      if(vacia(lis)){
        // Si la lista esta vacia, establecer como nulo el campo anterior del nuevo nodo
            lis->fin=nuevoNodo;
		    lis->inicio=nuevoNodo;
            nuevoNodo->anterior=NULL;
      }
         else{
            lis->fin->siguiente=nuevoNodo;
            // Asignar el ultimo elemento al campo anterior del nuevo nodo
            nuevoNodo->anterior = lis->fin;
            lis->fin=nuevoNodo;
      }
       lis->numElem++;
      return 0;
}

int insertarPos(Lista *lis, char dato, int pos ){
int i;
nodo *tmp, *nuevoNodo;
       if(pos <= 0 || pos > lis->numElem)
       {  
                printf("esa posicion no existe debe ser de a a %d", lis->numElem);
       		return -1; 
       	}
        
        nuevoNodo=creaNodo(dato);
	    
	    if(nuevoNodo==NULL){
	 	   return 1;
	    }  
       
       if (pos == 0)
        { 
	        printf("\n usar insertar al inicio"); 
			return -1;
        }
	   
	    tmp=lis->inicio;
	    
        for(i=1;i<pos;i++){ 
       
           tmp=tmp->siguiente;
          
        }
        
        printf("\npos %d", pos);
        
        if(tmp->siguiente==NULL){ 
           printf("\n usar insertar al final");   
           return -1;
       }
        nuevoNodo->siguiente = tmp->siguiente;
        nuevoNodo->anterior=tmp; 
        tmp->siguiente=nuevoNodo; 
        tmp->siguiente->anterior=nuevoNodo;
        // if (nuevoNodo->siguiente != NULL)
        // {
        //     nuevoNodo->siguiente->anterior = nuevoNodo;
        // }
       lis->numElem++;
       return 0;
}

int insertarPos_antes(Lista *lis, char dato, int pos ){
int i;
nodo *tmp, *nuevoNodo;
       if(pos <= 0 || pos > lis->numElem)
       {  
                printf("esa posicion no existe debe ser de a a %d", lis->numElem);
       		return -1; 
       	}
        
        nuevoNodo=creaNodo(dato);
	    
	    if(nuevoNodo==NULL){
	 	   return 1;
	    }  
       
       if (pos == 0)
        { 
	        printf("\n usar insertar al inicio"); 
			return -1;
        }
	   
	    tmp=lis->inicio;
	    
        for(i=1;i<pos-1;i++){ 
       
           tmp=tmp->siguiente;
          
        }
        
        printf("\npos %d", pos);
        
        if(tmp->siguiente==NULL){ 
           printf("\n usar insertar al final");   
           return -1;
       }
        nuevoNodo->siguiente = tmp->siguiente;
        nuevoNodo->anterior=tmp; 
        tmp->siguiente=nuevoNodo; 
        tmp->siguiente->anterior=nuevoNodo;
        // if (nuevoNodo->siguiente != NULL)
        // {
        //     nuevoNodo->siguiente->anterior = nuevoNodo;
        // }
       lis->numElem++;
       return 0;
}

char eliminarPos(Lista *lis, int pos){
        nodo *tmp,*nodoElim;
        char dato;
        int i;

        if(vacia(lis)){
         printf("\n lista vacia");
            return -1.0;
         }
        if(pos < 0 || pos > lis->numElem)
        {
            
          printf ("\nposiciÃ³n no valida");  
                return -2;              
		}
		if (pos==0) { 
		     
            if(lis->inicio==lis->fin){  
	            inicializacion(lis);
            }
	        else { 
				
	             nodoElim=lis->inicio; 
                 lis->inicio=lis->inicio->siguiente; 
                //  Actualizar el campo siguiente del ultimo nodo en la lista
                 lis->fin->siguiente=lis->inicio;
				}
        }
        else { 
            
            tmp=lis->inicio;    
            for(i=0;i<pos;i++) { 
                tmp=tmp->siguiente;
            }
            if(tmp->siguiente==NULL){
               printf("\nLa posicion dada es del ultimo elemento, para borrarlo colocar posicion del peultimo");
                return -3;
            }
           nodoElim=tmp->siguiente; 
           tmp->siguiente=lis->inicio;
       }
       lis->numElem--;

        dato=nodoElim->dato; 
        free(nodoElim);
        return  dato;

}

void mostrar( Lista *lis ){
	nodo *tmp;
	int cont=0;
	tmp=lis->inicio;
	while(cont != lis->numElem){
		printf("\n dato = %c ",tmp->dato);
		tmp=tmp->siguiente;
		cont++;
	}	
}

void mostrar_rev( Lista *lis){
    nodo *tmp;
    int cont=0;
    tmp=lis->fin;
    while (cont != lis->numElem)
    {
        printf("\n dato = %c ", tmp->dato);
        tmp=tmp->anterior;
        cont++;
    }    
}

int buscarElemento(Lista *lis, char elemento){
    nodo *tmp;
    int cont=0;
    // El nodo temporal inicia en el inicio de la lista
    tmp=lis->inicio;
    while (cont != lis->numElem)
    {
        if(tmp->dato == elemento){
            return cont;
        }
        tmp=tmp->siguiente;
        cont++;
    }
    return -1;
}

int main(int argc, char const *argv[])
{   
    Lista lista1; 
    int i;
    
    inicializacion(&lista1);

    printf("Insertando a al inicio de la lista :\n");
    insertarInicio(&lista1, 'a');
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando b al inicio de la lista :\n");
    insertarInicio(&lista1, 'b');
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando c al inicio de la lista :\n");
    insertarInicio(&lista1, 'c');
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando f al final de la lista :\n");
    insertarFinal(&lista1, 'f');
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando d en posicion 2 :\n");
    insertarPos(&lista1, 'd', 2);
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Eliminando inicio y fin :\n");
    eliminarPos(&lista1, 0);
    eliminarPos(&lista1, 3);
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Probando la funcion de mostrar de fin a inicio :\n");
    mostrar_rev(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando t antes de la posicion 2 :\n");
    insertarPos_antes(&lista1, 't', 2);
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Localizacion del elemento t en la lista : %d\n", buscarElemento(&lista1, 't'));
    printf("Localizacion del elemento z en la lista (no existe) : %d\n", buscarElemento(&lista1, 'z'));
    printf("\n-------------------------------------\n");
    
    return 0;
}


