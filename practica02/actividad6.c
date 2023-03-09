/******************************************************************************
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Practica 2 - Actividad 6
*******************************************************************************/
#include <stdio.h>

#define MAXSIZE 100
void reverseString(char *string, char *rev);

int main(int argc, char const *argv[])
{
    char str[MAXSIZE], str_reversed[MAXSIZE];
    scanf("%s", str);
    reverseString(str, str_reversed);
    printf("%s", str_reversed);
    return 0;
}

void reverseString(char *string, char *rev){
    int size, i=0, j=0; 

    // Measure the size of the given string
    while(*(string + i) != '\0'){
        i++; 
    }
    size = i; 

    // Generate a reversed string
    for (i = size-1; i >= 0; i--)
    {
        *(rev + j++) = *(string + i);
    }
}