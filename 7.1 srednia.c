#include <stdio.h>


void losowanieWartosci(int n, int tab[n]){
    int i,j;
    srand(time(NULL));
    for(i=0;i<n;i++){
        tab[i]=rand()%30;
    }
}

void wyswietlZakres(int*od, int*doo){
    for(;od<doo;++od){
        printf("%d ",*od);
    }
}

void srednia(int*od, int*doo){ //waga kazdego elementu to jego indeks w tablicy zaczynajac od 0
    double licznik=0,mianownik=0,wynik;
    int waga=0;
    for(;od<doo;++od){
        licznik+=(*od)*waga;
        mianownik+=waga;
        ++waga;
    }
    wynik=licznik/mianownik;
    printf("\nSrednia wazona elementow tablicy wynosi: %.2lf\n\n",wynik);
}

int main(void){
    int tab[10];
    losowanieWartosci(10,tab);
    int *wsk=tab;
    const int N=sizeof(tab)/sizeof(tab[0]);
    printf("Tablica: ");
    wyswietlZakres(tab,tab+N);
    srednia(tab,tab+N);
    return 0;
}
