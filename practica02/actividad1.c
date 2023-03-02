/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 2 - Actividad 1
*******************************************************************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a, *ap; 
    a = 7.5; 
    ap = &a;
    printf("Direccion y valor de a: %p, %f\n", &a, a);
    printf("Direccion y valor de ap: %p, %p\n", &ap, ap);
    printf("Valor almacenado en la direccion ap: %f\n", *ap);
    *ap -= 1; 
    printf("Nuevo valor de a: %f\n", a);
    return 0;
}
