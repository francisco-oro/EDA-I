/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 3 - Actividad 1
*******************************************************************************/

#include <stdio.h>
#include <math.h>

struct r3 {
    float x;
    float y;
    float z; 
};

void r3_input(struct r3 *v); 
void r3_display(struct r3 v);
void r3_magnitude(struct r3 v, float *mod);
float r3_dotProduct(struct r3 v, struct r3 u);
void r3_sum(struct r3 v, struct r3 u, struct r3 *w);
void r3_diff(struct r3 v, struct r3 u, struct r3 *w);

int main(int argc, char const *argv[])
{
    struct r3 v, u, sum, diff;
    float modulus; 
    r3_input(&v);
    r3_display(v);
    r3_input(&u);
    r3_display(u);
    r3_magnitude(v, &modulus);
    printf("Module of v= %.2f\n", modulus);
    printf("Dot product v cdot u= %.2f\n", r3_dotProduct(v, u));
    r3_sum(v, u, &sum);
    r3_diff(v, u, &diff);
    r3_display(sum);
    r3_display(diff); 
    return 0;
}

void r3_input(struct r3 *n){
    printf("Input values: \n");
    scanf("%f", &n->x);
    scanf("%f", &n->y);
    scanf("%f", &n->z); 
}

void r3_display(struct r3 v){
    printf("(%f, %f, %f)\n", v.x, v.y, v.z);
}

void r3_magnitude(struct r3 v, float *mod){
    *mod = sqrt(pow(v.x,2)+pow(v.y,2)+pow(v.z,2));
}

float r3_dotProduct(struct r3 v, struct r3 u){
    return (v.x*u.x+v.y*u.y+v.z*u.z);
}

void r3_sum(struct r3 v, struct r3 u, struct r3 *w){
    w->x=v.x+u.x;
    w->y=v.y+u.y;
    w->z=v.z+u.z;
}

void r3_diff(struct r3 v, struct r3 u, struct r3 *w){
    w->x=v.x-u.x;
    w->y=v.y-u.y;
    w->z=v.z-u.z;
}