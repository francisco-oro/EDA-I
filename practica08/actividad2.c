/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 8 - Actividad 2 
*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>


struct NodoLista{
      double dato;
      struct NodoLista *siguiente;
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
        // Establecer el la direccion de inicio de dicho nodo en el campo siguiente
        nuevoNodo->siguiente=nuevoNodo;
		    
    }
     else{
           nuevoNodo->siguiente=lis->inicio;
	       lis->inicio=nuevoNodo;
            // Establecer la direccion de inicio del nuevo nodo creado en el campo siguiente del ultimo nodo en la lista
           lis->fin->siguiente = nuevoNodo; 
	 }
     
     lis->numElem++;
     return 0;
}


int  insertarFinal(Lista *lis, float dato){
      nodo *nuevoNodo;
	 
	 nuevoNodo=creaNodo(dato);
	 if(nuevoNodo==NULL){
	 	return 1;
	 }  
      if(vacia(lis)){
            lis->fin=nuevoNodo;
		    lis->inicio=nuevoNodo;
            // Establecer la direccion de inicio de dicho nodo en el campo siguiente
            nuevoNodo->siguiente=nuevoNodo;		
		  
      }
         else{
            lis->fin->siguiente=nuevoNodo;
            lis->fin=nuevoNodo;
            nuevoNodo->siguiente=lis->inicio;
            // Establecer la direccion de inicio del primer nodo en el campo siguiente del ultimo nodo agregado.
      }
       lis->numElem++;
      return 0;
}

int insertarPos(Lista *lis, float dato, int pos ){
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
      
       nuevoNodo->siguiente=tmp->siguiente;
       tmp->siguiente=nuevoNodo;
       lis->numElem++;
       return 0;
}


float eliminarPos(Lista *lis, int pos){
        nodo *tmp,*nodoElim;
        float dato;
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
            // Es necesario inicialiar la variable de control en 0 para alcanzar el ultimo elemento para la lista circular
            for(i=0;i<pos;i++) { 
                tmp=tmp->siguiente;
            }
            if(tmp->siguiente==NULL){
               printf("\nLa posicion dada es del ultimo elemento, para borrarlo colocar posicion del peultimo");
                return -3;
            }
           nodoElim=tmp->siguiente; 
            // Actualizar el campo siguiente del nodo (ahora debe ser la direccion del primer nodo)
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
		printf("\n dato = %f ",tmp->dato);
		tmp=tmp->siguiente;
		cont++;
	}
	
}

int main(int argc, char const *argv[])
{   
    Lista lista1; 
    int i;
    
    inicializacion(&lista1);

    printf("Insertando dos elementos al inicio de la lista :\n");
    for (i = 0; i < 2; i++)
    {
        insertarInicio(&lista1, rand()%20);
    }
    for (i = 0; i < 2; i++)
    {
        printf("\n ->Vuelta %d : \n", i+1);
        mostrar(&lista1);
    }
    
    printf("\n-------------------------------------\n");

    printf("Insertando dos elementos al final de la lista :\n");
    for (i = 0; i < 2; i++)
    {
        insertarFinal(&lista1, rand()%20);
    }
    for (i = 0; i < 2; i++)
    {
        printf("\n ->Vuelta %d : \n", i+1);
        mostrar(&lista1);
    }
    printf("\n-------------------------------------\n");

    printf("Insertando un elemento despues de la posicion 2 :\n");
    insertarPos(&lista1, rand()%20, 3);
    for (i = 0; i < 2; i++)
    {
        printf("\n ->Vuelta %d : \n", i+1);
        mostrar(&lista1);
    }
    printf("\n-------------------------------------\n");

    printf("Borrando el primer elemento :\n");
    printf("Valor eliminado : %f\n", eliminarPos(&lista1, 0));
    printf("Borrando el ultimo elemento :\n");
    printf("Valor eliminado : %f\n", eliminarPos(&lista1, 2));
    for (i = 0; i < 3; i++)
    {
        printf("\n->Vuelta %d : \n", i+1);
        mostrar(&lista1);
    }
    
    printf("\n-------------------------------------\n");

    return 0;
}



