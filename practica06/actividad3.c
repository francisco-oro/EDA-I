/******************************************************************************
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 6 - Actividad 3
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct songInstance
{
    char name[20];
    int YOL;   
};

typedef struct songInstance si;

struct colaC{
    si *songs;
    int ini, fin, ne, n;
};

typedef struct colaC cQueue;

void startcQueue(cQueue *cq, int n);
int fullcQueue(cQueue *cq);
int emptycQueue (cQueue*cq);
void enQueue(cQueue *cq, si newValue);
si deQueue(cQueue *cq);
void displayQueue(cQueue *cq);
void freeQueue(cQueue *cq);
si newSong();
void displaySong(si *song);

int main(int argc, char const *argv[]){
    cQueue queue1;
    si currentSong;
    int i;

    startcQueue(&queue1, 4);
    for (i = 0; i < 4; i++)
    {   
        currentSong = newSong();
        enQueue(&queue1, currentSong);
        displayQueue(&queue1); 
    }

    return 0;
}

void startcQueue(cQueue *cq, int n){
    cq->ini=0;
    cq->fin=0;
    cq->ne=0;
    cq->n = n;
    cq->songs=(si *)calloc(n, sizeof(si));
}

int fullcQueue(cQueue *cq){
    if(cq->ini == cq->fin && cq->ne==cq->n) return 1;
    else return 0;
}

int emptycQueue (cQueue*cq){
    if(cq->ini == cq->fin && cq->ne==0) return 1;
    return 0;
}

void enQueue(cQueue *cq, si newValue){
    if(!fullcQueue(cq)){
        cq->songs[cq->fin]=newValue;
        cq->ne++;
        cq->fin = (cq->fin+1)%cq->n; 
    } else {
        printf("\nThis queue is full\n");
    }
}

si deQueue(cQueue *cq){
    si data;
    if(!emptycQueue(cq)){
        data = cq->songs[cq->ini];
        cq->ini=(cq->ini+1)%cq->n;
        cq->ne--;
        return data;
    } else {
        printf("This queue is empty");
    }
}

void displayQueue(cQueue *cq){
    int i, index;
    index = cq->ini;
    printf("\n");
    for (i = cq->ini; i < cq->ne; i++)
    {
        displaySong(&cq->songs[index]);
        index=(index+1)%cq->n;
    }
    printf("\n");
}

void freeQueue(cQueue *cq){
    free(cq->songs);
}

si newSong(){
    si temp;
    printf("Ingrese el nombre de la cancion: ");
    scanf(" %s", temp.name);
    printf("Ingrese el ano de lanzamiento:");
    scanf("%d", &temp.YOL);
    return temp;
}

void displaySong(si *song){
    printf("name: %s\n", song->name);
    printf("ano de lanzamiento: %d\n", song->YOL);
}