/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 9 - Actividad 1
*******************************************************************************/

#include <stdio.h>
#include "SQcar.h"
#include <stdlib.h>
#include <string.h>

char etopet(tpila *pila){
    nodo *tmp;
    if (!vaciaP(pila))
    {
        return 1;
    }
    else {
        tmp=pila->tope;
        return tmp->dato; 
    }    
    return 1;
}

int prioridad(char c){
    switch (c)
    {
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '%':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    tpila s1;
    tq qsal; 
    char *exp, currentChar, aChar;
    int number_of_characters;

    creaPila(&s1); 
    creaCola(&qsal);
    exp = (char *)malloc(30 * sizeof(char));
    printf("Ingrese su expresion : ");
    fgets(exp, 30, stdin);
    number_of_characters = strlen(exp);

    for (size_t i = 0; i < number_of_characters; i++)
    {
        currentChar = exp[i];
        printf("\nReading value %c ->", currentChar);
        if (currentChar == ' ' || currentChar == '\t')
        {
            continue;
        }
        // If the scanned character is opperand, add it to the queue
        else if ((currentChar >= '0' && currentChar <= '9') || (currentChar >= 'a' && currentChar <= 'z'))
        {
            encolar(&qsal, currentChar);
        }
        // If the scanned character is '(', push it in the stack
        else if (currentChar == '(')
        {
            push(&s1, currentChar);
        }
        // If the scanned character is ')', pop the stack and add it to the output string until empty or "(" found 
        else if (currentChar == ')')
        {
            aChar = pop(&s1);
            while (vaciaP(&s1) && (aChar != '('))
            {
                encolar(&qsal, aChar);
                aChar = pop(&s1); 
            }
        }
        // If the scanned character is an operator, push it in the stack
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '%')
        {
            while (vaciaP(&s1) &&  (prioridad(etopet(&s1)) >= prioridad(currentChar)))
            {
                encolar(&qsal, pop(&s1));
            }
            push(&s1, currentChar);
        }
    }
    // Pop all the remaining elements from the stack
    while (vaciaP(&s1))
    {
        aChar = pop(&s1);
        encolar(&qsal, aChar);
    }
    printf("\nPostfix notation : ");
    mostrarQ(&qsal);
    return 0;
}
