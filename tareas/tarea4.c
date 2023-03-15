/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Tarea 4
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define n 30

struct alumno
{
    char *nombre;
    float prom;
    int edad;
};


int main(int argc, char const *argv[])
{
    
    struct alumno *arr;
    int i;

    arr = (struct alumno *)malloc(3 * sizeof(struct alumno));

    if(arr==NULL){
        printf("La memoria no pudo ser reservada\n");
        exit(0);
    }
    // Llenado de datos
    for (i = 0; i < 3; i++)
    {
        (arr + i)->nombre = (char*)calloc(n,sizeof(char));
        printf("Ingrese su nombre\n");
        scanf("%s", (arr+i)->nombre);

        printf("Ingrese promedio\n");
        scanf("%f", &(arr+i)->prom);

        printf("Ingrese edad\n");
        scanf("%d", &(arr+i)->edad);
    }
    // Impresión de datos
    for (i = 0; i < 3; i++)
    {
        printf("Alumno %d:\n", i+1);
        printf("Nombre: %s\n", (arr+i)->nombre);
        printf("Promedio: %f\n", (arr+i)->prom);
        printf("Edad: %d\n\n", (arr+i)->edad);
    }
    
}
