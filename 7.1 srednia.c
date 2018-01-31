#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ILOSC 10


void losowanieWartosci(int tab[ILOSC]){
    srand(time(NULL));
    for(int i=0; i<ILOSC; i++){
        tab[i]=rand()%30;
    }
}

void wyswietlZakres(int *od, int *doo){
    printf("Tablica: ");
    for(; od<doo; ++od){
        printf("%d ", *od);
    }
}

void srednia(int *od, int *doo){ //waga kazdego elementu to jego indeks w tablicy zaczynajac od 0
    double licznik=0, mianownik=0, wynik;
    int waga=0;
    for(; od<doo; ++od){
        licznik+=(*od)*waga;
        mianownik+=waga;
        ++waga;
    }
    wynik=licznik/mianownik;
    printf("\nSrednia wazona elementow tablicy wynosi: %.2f\n\n", wynik);
}

int main(void){
    int tab[ILOSC];
    losowanieWartosci(tab);
    int *wsk=tab;
    const int N=sizeof(tab)/sizeof(tab[0]);
    wyswietlZakres(tab, tab+N);
    srednia(tab, tab+N);
    return 0;
}
