/******************************************************************************;
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 4 - Actividad 4
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct complex *newSet(int n);
struct complex *multiplySets(struct complex *set1, struct complex *set2); 
void displaySet(struct complex *set1);

struct complex 
{
    float modulus;
    float angle; 
};

int main(int argc, char const *argv[])
{
    // Define three sets of complex numbers
    struct complex *A, *B, *C;
    A = newSet(MAXSIZE);
    B = newSet(MAXSIZE);
    C = multiplySets(A, B);
    printf("\nSet A\n");
    displaySet(A);
    printf("\nSet B\n");
    displaySet(B);
    printf("\nSet C \\Rightarrow  C = B*A \n");
    displaySet(C);
    return 0;
}

struct complex *newSet(int n){
    int i;
    struct complex *set;
    set = (struct complex *)calloc(n, sizeof(struct complex));
    for (i = 0; i < n; i++)
    {
        // Each angle lies on the interval [0,360)
        set[i].angle = (rand()%360); 
        // Each modulus lies on the interval [0,10]
        set[i].modulus = (rand()%10);
    }
    return set;
}

struct complex *multiplySets(struct complex *set1, struct complex *set2){
    int i;
    struct complex *_set;
    _set = (struct complex *)calloc(MAXSIZE, sizeof(struct complex));
    for (i = 0; i < MAXSIZE; i++)
    {
        // Add up the angles
        _set[i].angle = set1[i].angle + set2[i].angle;
        // Ensure there's no chance to surpass 360deg
        if(_set[i].angle >= 360) _set[i].angle = _set[i].angle - 360;
        // Multiply the modulus
        _set[i].modulus = set1[i].modulus * set2[i].modulus;
    }
    return _set; 
}

void displaySet(struct complex *set1){
    int i;
    for (i = 0; i < MAXSIZE; i++)
    {
        printf("%.2f cis (%.3f), ", set1[i].modulus, set1[i].angle);
    }
    printf("\n");
}