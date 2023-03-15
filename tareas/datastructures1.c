/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Tarea: Pro
*******************************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct r3
{
    float x;
    float y; 
    float z; 
};

void assign(struct r3 *n);
void sum(struct r3 nn1, struct r3 nn2, struct r3 *ap);
float distanceBetween(struct r3 nn1, struct r3 nn2);

int main(int argc, char const *argv[])
{
    struct r3 n[5];
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("p%d= ", i+1);
        assign(n+i);
    }
    printf("p1 + p2 = ");
    sum(*n, *(n+1), n+4);
    printf("Distance between p1 and p2: %f", distanceBetween(*n, *(n+2)));
    return 0;
}

void assign(struct r3 *n){
    n->x=rand()%30; 
    n->y=rand()%10; 
    n->z=3.5; 
    printf("(%.2f, ", n->x);
    printf("%.2f, ", n->y);
    printf("%.2f)\n", n->z);
}

void sum(struct r3 nn1, struct r3 nn2, struct r3 *ap){
    ap->x=nn1.x + nn2.x;
    ap->y=nn1.y+nn2.y;
    ap->z=nn1.z+nn2.z;
    printf("(%.2f, ", ap->x);
    printf("%.2f, ", ap->y);
    printf("%.2f)\n", ap->z);
}

float distanceBetween(struct r3 nn1, struct r3 nn2){
    return(sqrt(pow((nn2.x-nn1.x),2)+pow((nn2.y-nn1.y),2)+pow((nn2.z-nn1.z),2)));
}