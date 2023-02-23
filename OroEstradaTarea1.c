#include <stdio.h>

int main() {
    float calif[50], suma = 0, prom;
    int i, numEst = 0, n;

    printf("Introduzca n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Introduzca la calif %d: ", i + 1);
        scanf("%f", &calif[i]);
        suma += calif[i];
    }
    prom = suma / n;

    for (i = 0; i < n; i++) {
        if (calif[i] > prom) {
            numEst++;
        }
    }
    printf("Promedio: %f\t", prom);
    printf("numEst: %d", numEst);
}