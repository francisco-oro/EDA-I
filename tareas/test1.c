/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Test - 1
*******************************************************************************/
#include<stdio.h>
#define n 10
#include<stdlib.h>
#include<time.h>

int main()
{
    int a[n][n],b[n][n],c[n][n]; //Recuerda que a,b y c ya son apuntadores (tienen la dirección de inicio de cada arreglo). 
    int i,j;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            *(*(a+i)+j)=rand()%n;  // No olvides usar asteriscos toda vez que vas a modificar el valor del elemento que está en la dirección de tu apuntador. 
            *(*(b+i)+j)=rand()%n;
            *(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",*(*(a+i)+j));
        }
        printf("\n");
    }
        for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",*(*(b+i)+j));
        }
        printf("\n");
    }    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",*(*(c+i)+j));
        }
        printf("\n");
    }
    return 0;
    
}