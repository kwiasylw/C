#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ILOSCELEMENTOW 10

int main(void) {
    int tab[10];
    srand(time(NULL));
    for (int i=0; i<ILOSCELEMENTOW; i++){
        tab[i]=rand()%30;
    }
    int *wsk[10];
    puts("***POCZATKOWO***");
    puts("L.P.\ttab A\ttab B");
    puts("---------------------");
    for (int j=0; j<ILOSCELEMENTOW; j++){
        wsk[j]=&tab[j];
    }
    for (int j=0; j<ILOSCELEMENTOW; j++){
        printf("%d\t%d\t%d\n", j, tab[j], *wsk[j]);
    }

    int *tmp;
    //sortowanie
    for (int k=0; k<ILOSCELEMENTOW; k++){
        for (int j=0; j<ILOSCELEMENTOW-1; j++){
            if (*wsk[j]>*wsk[j+1]){
                tmp=wsk[j+1];
                wsk[j+1]=wsk[j];
                wsk[j]=tmp;
            }
        }
    }

    puts("\n");
    puts("***REZULTAT KONCOWY***");
    puts("L.P.\ttab A\ttab B");
    puts("---------------------");
    for (int j=0; j<ILOSCELEMENTOW; j++){
        printf("%d\t%d\t%d\n", j, tab[j], *wsk[j]);
   }
    return 0;
}
