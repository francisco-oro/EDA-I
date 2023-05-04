/******************************************************************************;
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
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

void blue () {
  printf("\033[0;34m");
}

void reset () {
  printf("\033[0m");
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

int insertarFinal(Edificio*lis, int dato){
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

void inicializacion(Edificio *lista, int size){
    piso *nuevopiso;
    lista->inicio = NULL;
    lista->fin = NULL;
    lista->numElem = 0;
    for (size_t i = n; i > 0; i--)
    {
        insertarFinal(lista, i);
    }
}



int BuscarPiso( Edificio*lis, int numPiso ){
	piso *tmp;
	int cont=0;
    char alias[2];
	tmp=lis->inicio;

    if (numPiso < 1 || numPiso > lis->numElem){
        printf("Ese piso no esta disponible");
        return -1;
    }
	while(cont != lis->numElem){
        if(tmp->dato == numPiso){
            blue();
            printf("\n Piso = %d", tmp->dato);
            if(numPiso == 1){
                printf(" -> PB");
            }
            if (numPiso == lis->numElem)
            {
                printf(" -> PH");
            }
            reset();
            tmp=tmp->siguiente;
            cont++;
            continue;
        }
		printf("\n Piso = %d ",tmp->dato);
		tmp=tmp->siguiente;
		cont++;
	}	
}

int main(int argc, char const *argv[])
{   
    Edificio edificio1; 
    int i;
    
    printf("Creando el edificio:\n");
    inicializacion(&edificio1, n);
    printf("\n-------------------------------------\n");

    while (1)
    {
        printf("\nIngrese el piso a buscar o -1 para salir : \n");
        scanf("%d", &i);
        if (i == -1) break; 
        BuscarPiso(&edificio1, i);
    }
    return 0;
}


