/******************************************************************************;
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 4 - Actividad 3
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct polinomio newPol(int deg); 
void displayPol(struct polinomio pol1);
struct polinomio addPols(struct polinomio pol1, struct polinomio pol2);

struct polinomio {
    unsigned int grado; 
    int *coeficientes; 
};

int main(int argc, char const *argv[])
{
    struct polinomio f, g, sum;
    int n; 
    printf("Grado de f(x): ");
    scanf("%d",&n);
    f = newPol(n);
    printf("Grado de g(x): ");
    scanf("%d",&n);
    g = newPol(n);

    printf("Los polinomios generados son\n");
    displayPol(f);
    displayPol(g);

    printf("La suma de f(x)+g(x) es\n");
    sum = addPols(f, g);
    displayPol(sum);
    return 0;
}

struct polinomio newPol(int deg){
    int i;
    struct polinomio pol; 
    pol.grado = deg;
    pol.coeficientes = (int *)calloc(deg+1, sizeof(int)); 
    for (i = 0; i <= deg; i++)
    {
        pol.coeficientes[i]=(rand()%10);
    }
    return pol;
}

void displayPol(struct polinomio pol1){
    int i;
    for(i=pol1.grado; i>0; i--){
        printf("%dx^%d + ", pol1.coeficientes[i], i);
    }
    printf("%d", pol1.coeficientes[i]);
    printf("\n");
}

struct polinomio addPols(struct polinomio pol1, struct polinomio pol2){
    /* The order variable is needed to determine which polynomial has the greatest degree: 
        0 : pol2 > pol1 
        1 : pol1 > pol2
    */
    int i, smallestDeg, order;
    struct polinomio _pol; 
    // This new polynomial must have the greatest degree
    if(pol2.grado>pol1.grado){
        _pol.grado = pol2.grado;
        smallestDeg = pol1.grado;
        order=0;
    } 
    else
    {
       _pol.grado = pol1.grado;
       smallestDeg = pol2.grado;
       order=1;
    }
    

    _pol.coeficientes = (int *)calloc(_pol.grado + 1, sizeof(int));

    // Compute the sum of pol1 plus pol2 and store each value in _pol
    
    for (i = 0; i <= smallestDeg; i++)
    {
        _pol.coeficientes[i]=pol1.coeficientes[i]+pol2.coeficientes[i];
    }
    for (i; i <= _pol.grado; i++)
    {
        // Display the missing terms based on the order variable (Further information provided at the beginning of this function)
        if(order)_pol.coeficientes[i]=pol1.coeficientes[i];
        else _pol.coeficientes[i]=pol2.coeficientes[i];
    }
    return _pol; 
}