#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WYMIAR 3


void losowanieWartosci(int a[WYMIAR][WYMIAR]){
    srand(time(NULL));
    for(int i=0; i<WYMIAR; ++i){
        for(int j=0; j<WYMIAR; ++j){
            a[i][j]=rand()%10;
        }
    }
}

void wypisywanieMacierzy(int a[WYMIAR][WYMIAR]){
    for(int i=0; i<WYMIAR; ++i){
        printf("\n");
        for(int j=0; j<WYMIAR; ++j){
            printf("%d\t", a[i][j]);
        }
    }
}

void obliczanieWyznacznika(int a[WYMIAR][WYMIAR]){
    int wyznacznik;
    wyznacznik=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]-a[0][2]*a[1][1]*a[2][0]-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2];
    printf("\n\nWyznacznik tej macierzy 3x3 wynosi: %d\n\n", wyznacznik);
}


int main(){
    int a[WYMIAR][WYMIAR];
    printf("Program oblicza wyznacznik macierzy 3x3 o losowo wybranych wartosciach.\n");
    losowanieWartosci(a);
    printf("\nMacierz ma postac:");
    wypisywanieMacierzy(a);
    obliczanieWyznacznika(a);
    return 0;
}
