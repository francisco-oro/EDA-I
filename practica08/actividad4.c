/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 8 - Actividad 4
*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

#define n 10

struct NodoLista{
      int dato;
      struct NodoLista *siguiente;
      struct NodoLista *anterior;
};


typedef  struct NodoLista piso;
struct controlLista{
piso *inicio;  
piso *fin;
int numElem;
};

typedef struct controlLista Edificio;


void inicializacion(Edificio *lista, int size){
    piso *nuevopiso, *tmp;
    // Primer piso
    nuevopiso = creapiso(1);
    lista->inicio = nuevopiso;
    lista->fin= nuevopiso;
    lista->inicio->anterior=NULL; 
    for (size_t i = 1; i < size; i++)
    {
        tmp = creapiso(i+1);
        
    }
    
}

int vacia(Edificio*lis){
	if(lis->inicio==NULL && lis->fin==NULL && lis->numElem==0)
	   return 1;
	else
	    return 0;
}

piso *creapiso(double dato){
	piso  *nuevopiso;
    nuevopiso=(piso *)malloc(sizeof(piso));
     if(nuevopiso!=NULL){
      nuevopiso->dato=dato;
      nuevopiso->siguiente=NULL;
      nuevopiso->anterior=NULL;
     }
    return nuevopiso;
	
}


int insertarInicio (Edificio*lis, double dato){
	 piso *nuevopiso;
	 
	 nuevopiso=creapiso(dato);
	 if(nuevopiso==NULL){
	 	return 1;
	 }  

    if( vacia(lis)){
        lis->fin=nuevopiso;
		lis->inicio=nuevopiso;		
        nuevopiso->anterior=NULL;
    }
     else{
            // Asignar el siguiente del nuevo piso y dejar como nulo el campo del piso anterior
           nuevopiso->siguiente=lis->inicio;
	       lis->inicio=nuevopiso;
           nuevopiso->siguiente->anterior=nuevopiso;
           nuevopiso->anterior= NULL;
	 }
     
     lis->numElem++;
     return 0;
}   


int  insertarFinal(Edificio*lis, char dato){
      piso *nuevopiso;
	 
	 nuevopiso=creapiso(dato);
	 if(nuevopiso==NULL){
	 	return 1;
	 }  
      if(vacia(lis)){
        // Si la Edificioesta vacia, establecer como nulo el campo anterior del nuevo piso
            lis->fin=nuevopiso;
		    lis->inicio=nuevopiso;
            nuevopiso->anterior=NULL;
      }
         else{
            lis->fin->siguiente=nuevopiso;
            // Asignar el ultimo elemento al campo anterior del nuevo piso
            nuevopiso->anterior = lis->fin;
            lis->fin=nuevopiso;
      }
       lis->numElem++;
      return 0;
}

int insertarPos(Edificio*lis, char dato, int pos ){
int i;
piso *tmp, *nuevopiso;
       if(pos <= 0 || pos > lis->numElem)
       {  
                printf("esa posicion no existe debe ser de a a %d", lis->numElem);
       		return -1; 
       	}
        
        nuevopiso=creapiso(dato);
	    
	    if(nuevopiso==NULL){
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
        nuevopiso->siguiente = tmp->siguiente;
        nuevopiso->anterior=tmp; 
        tmp->siguiente=nuevopiso; 
        tmp->siguiente->anterior=nuevopiso;
        // if (nuevopiso->siguiente != NULL)
        // {
        //     nuevopiso->siguiente->anterior = nuevopiso;
        // }
       lis->numElem++;
       return 0;
}

int insertarPos_antes(Edificio*lis, char dato, int pos ){
int i;
piso *tmp, *nuevopiso;
       if(pos <= 0 || pos > lis->numElem)
       {  
                printf("esa posicion no existe debe ser de a a %d", lis->numElem);
       		return -1; 
       	}
        
        nuevopiso=creapiso(dato);
	    
	    if(nuevopiso==NULL){
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
        nuevopiso->siguiente = tmp->siguiente;
        nuevopiso->anterior=tmp; 
        tmp->siguiente=nuevopiso; 
        tmp->siguiente->anterior=nuevopiso;
        // if (nuevopiso->siguiente != NULL)
        // {
        //     nuevopiso->siguiente->anterior = nuevopiso;
        // }
       lis->numElem++;
       return 0;
}

char eliminarPos(Edificio*lis, int pos){
        piso *tmp,*pisoElim;
        char dato;
        int i;

        if(vacia(lis)){
         printf("\n Edificiovacia");
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
				
	             pisoElim=lis->inicio; 
                 lis->inicio=lis->inicio->siguiente; 
                //  Actualizar el campo siguiente del ultimo piso en la lista
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
           pisoElim=tmp->siguiente; 
           tmp->siguiente=lis->inicio;
       }
       lis->numElem--;

        dato=pisoElim->dato; 
        free(pisoElim);
        return  dato;

}

void mostrar( Edificio*lis ){
	piso *tmp;
	int cont=0;
	tmp=lis->inicio;
	while(cont != lis->numElem){
		printf("\n dato = %c ",tmp->dato);
		tmp=tmp->siguiente;
		cont++;
	}	
}

void mostrar_rev( Edificio*lis){
    piso *tmp;
    int cont=0;
    tmp=lis->fin;
    while (cont != lis->numElem)
    {
        printf("\n dato = %c ", tmp->dato);
        tmp=tmp->anterior;
        cont++;
    }    
}

int buscarElemento(Edificio*lis, char elemento){
    piso *tmp;
    int cont=0;
    // El piso temporal inicia en el inicio de la lista
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
    Edificio lista1; 
    int i;
    
    inicializacion(&lista1);

    printf("Insertando a al inicio de la Edificio:\n");
    insertarInicio(&lista1, 'a');
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando b al inicio de la Edificio:\n");
    insertarInicio(&lista1, 'b');
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando c al inicio de la Edificio:\n");
    insertarInicio(&lista1, 'c');
    mostrar(&lista1);
    printf("\n-------------------------------------\n");

    printf("Insertando f al final de la Edificio:\n");
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

    printf("Localizacion del elemento t en la Edificio: %d\n", buscarElemento(&lista1, 't'));
    printf("Localizacion del elemento z en la Edificio(no existe) : %d\n", buscarElemento(&lista1, 'z'));
    printf("\n-------------------------------------\n");
    
    return 0;
}


