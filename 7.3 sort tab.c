#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ILOSCELEMENTOW 10


void losowanieWartosci(int tab[]){
    srand(time(NULL));
    for(int i=0; i<ILOSCELEMENTOW; i++){
        tab[i]=rand()%30;
    }
}

void przypisywanieWskaznikomOdpowiednichWartosciZTablicy(int tab[], int *wsk[]){
    for(int j=0; j<ILOSCELEMENTOW; j++){
        wsk[j]=&tab[j];
    }
}

void wypisywanieNaEkranZawartosciTablic(int tab[], int **wsk){
    puts("L.P.\ttab A\ttab B");
    puts("---------------------");
    for(int j=0; j<ILOSCELEMENTOW; j++){
        printf("%d\t%d\t%d\n", j, tab[j], *wsk[j]);
    }
}

void sortowanieBabelkowe(int **wsk){
    int *tmp;
    for(int k=0; k<ILOSCELEMENTOW; k++){
        for(int j=0; j<ILOSCELEMENTOW-1; j++){
            if(*wsk[j]>*wsk[j+1]){
                tmp=wsk[j+1];
                wsk[j+1]=wsk[j];
                wsk[j]=tmp;
            }
        }
    }
}

int main(void) {
    int tab[10], *wsk[10];
    losowanieWartosci(tab);
    puts("***POCZATKOWO***");
    przypisywanieWskaznikomOdpowiednichWartosciZTablicy(tab, wsk);
    wypisywanieNaEkranZawartosciTablic(tab, wsk);
    sortowanieBabelkowe(wsk);
    puts("\n\n***REZULTAT KONCOWY***");
    wypisywanieNaEkranZawartosciTablic(tab, wsk);
    return 0;
}
