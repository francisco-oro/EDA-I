/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 2 - Actividad 2
*******************************************************************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    short arr[5]={91, 28,73,46,55};
    int i; 
    for (i = 0; i < 5; i++)
    {
        *(arr + i)+=1; //Incremento de una unidad
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d \t", *(arr + i)); //Impresión de datos
    }
    
}
