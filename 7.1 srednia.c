#include <stdio.h>

void wyswietlZakres(int*od, int*doo){
    for(; od<doo;++od){
        printf("%d ", *od);
    }
}

void srednia(int*od, int*doo){ //waga kazdego elementu to jego indeks w tablicy zaczynajac od 0
    double licznik=0;
    double mianownik=0;
    int waga=0;
    double wynik;
    for(; od<doo;++od){
        licznik+=(*od)*waga;
        mianownik+=waga;
        ++waga;
    }
    wynik=licznik/mianownik;
    printf("\nSrednia wazona elementow tablicy wynosi: %.2lf\n\n",wynik);
}

int main(void){
    int  i,tab[10];
    srand(time(NULL));
    for(i=0;i<10;i++){
    tab[i]=rand()%30;
    }
    int *wsk=tab;
    const int N=sizeof(tab)/sizeof(tab[0]);
    printf("Tablica: ");
    wyswietlZakres(tab,tab+N);
    srednia(tab,tab+N);


        return 0;
}
