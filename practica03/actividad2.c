/******************************************************************************;
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 8 - Actividad 4
*******************************************************************************/
#include <stdio.h>
#define n 3

struct datosEstudiante 
{
    char nombre[30];
    int edad;
    char sexo;
    int notas[5];
};

struct registroEstudiante
{
    int numeroCuenta;
    struct datosEstudiante estudiante; 
};

void inputData(struct registroEstudiante *students);
void displayData(struct registroEstudiante *students);
void greatestGrade(struct registroEstudiante *students);

int main(int argc, char const *argv[])
{
    struct registroEstudiante students[n];
    inputData(students);
    displayData(students);
    greatestGrade(students);
    return 0;
}

void inputData(struct registroEstudiante *students){
    int i, j;
    for (j = 0; j < n; j++)
    {
        printf("Ingrese el nombre del estudiante %d: ", j);
        scanf("%s", (students+j)->estudiante.nombre);
        printf("No. de cuenta: ");
        scanf("%d", &(students+j)->numeroCuenta);
        printf("Edad: ");
        scanf("%d", &(students+j)->estudiante.edad);
        printf("Sexo: ");
        scanf(" %s", &(students+j)->estudiante.sexo);
        printf("Ingrese las notas:\n");
        for (i = 0; i < 5; i++)
        {
            printf("Nota %d: ", i+1);
            scanf("%d", &(students+j)->estudiante.notas[i]);
        }   
    }
}

void displayData(struct registroEstudiante *students){
    int i, j;
    for (j = 0; j < n; j++)
    {
        printf("\nNombre del estudiante: %s\n", students[j].estudiante.nombre);
        printf("No. de cuenta: %d\n", students[j].numeroCuenta);
        printf("Edad: %d\n", students[j].estudiante.edad);
        printf("Sexo: %c\n", students[j].estudiante.sexo);
        printf("Notas:\n");
        for (i = 0; i < 5; i++)
        {
            printf("Nota %d: %d\n", i+1, students[j].estudiante.notas[i]); 
        }
    }
}

void greatestGrade(struct registroEstudiante *students){
    int i, j, sum=0, gIndex;
    float mean[n], greatestGrade;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < 5; i++)
        {
            sum += students[j].estudiante.notas[i]; 
        }
        mean[j] = (sum/5.0);
        sum = 0;
        if(!j){
            greatestGrade = mean[j];
            gIndex = j;
        }
        if(mean[j] > greatestGrade){
            greatestGrade = mean[j];
            gIndex = j;
        }
    }

    printf("\nAlumno con el mejor promedio:\n");
    printf("Nombre: %s\n", (students + gIndex)->estudiante.nombre);
    printf("No. de cuenta %d\n", students[gIndex].numeroCuenta);
    printf("Promedio: %.2f\n", mean[gIndex]);
}