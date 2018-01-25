#include <stdio.h>
#include <ctype.h> //niestandardowa biblioteka
#include "projektSudoku.h"


int ogolnyLicznikNieustawionych=0;

struct czesciSkladowePlanszy pobierzCzesci(int indeks){
    struct czesciSkladowePlanszy zwroc;
    zwroc.wiersz=(int)(indeks/LINIE); //zwraca nr wiersza
    zwroc.kolumna=indeks%LINIE; //zwraca nr kolumny
    zwroc.malyKwadratSudoku=LINIEWCZESCI*(int)(zwroc.wiersz/LINIEWCZESCI)+(int)(zwroc.kolumna/LINIEWCZESCI); //zwraca nr kwadratu
    return zwroc;
}

void pokazPlanszeSudoku(int* rozwiazanie){
    printf(" -----------------------------------\n");
    for(int i=0; i<MAXILOSC; i++){
        if(i%LINIE==0){
            printf("|");
        }
        if(rozwiazanie[i]){
            printf(" %d ", rozwiazanie[i]);
        }
        else{
            printf("   ");
        }
        if(i%LINIE==(LINIE-1)){
            printf("|\n");
            if(i!=(MAXILOSC-1)){
                if(i%(LINIEWCZESCI*LINIE)==(LINIEWCZESCI*LINIE-1)){
                    printf("|-----------+-----------+-----------|\n");
                }
                else{
                    printf("|- - - - - -|- - - - - -|- - - - - -|\n");
                }
            }
        }
        else{
            printf("|");
        }
    }
    printf(" -----------------------------------");
}


int czyDanaWartoscJestJuzWTablicy(int* tablica, int wartosc, int dlugosc){
    for(int i=0; i<dlugosc; i++){
        if(tablica[i]==wartosc){
            return 1;
        }
    }
    return 0;
}

void wezPoziome(int wiersz, int* zwroc){
    int j=0;
    for(int i=(wiersz*LINIE); i<(wiersz*LINIE)+LINIE; i++){
        zwroc[j++]=niewiadoma[i];
    }
}

void wezPionowe(int kolumna, int* zwroc){
    int j=0;
    for(int i=kolumna; i<MAXILOSC; i+=LINIE){
        zwroc[j++]=niewiadoma[i];
    }
}

void wezKwadrat(int kolejne, int* zwroc){
    for(int i=0; i<LINIEWCZESCI; i++){
        for(int j=0; j<LINIEWCZESCI; j++){
            zwroc[LINIEWCZESCI*i+j]=niewiadoma[LINIE*i+kolejne*LINIEWCZESCI+j+((int)(kolejne/LINIEWCZESCI)*(LINIEWCZESCI-1)*LINIE)];
        }
    }
}

int ustawWartosci(int indeks, int niedozwolonaWartosc){
    int rzeczywistyIndeks=indeksy[indeks], elementy[LINIE];
    struct czesciSkladowePlanszy bloczki=pobierzCzesci(rzeczywistyIndeks);
    for(int i=1; i<=LINIE; i++){
        if(niedozwolonaWartosc && i==niedozwolonaWartosc){
            continue;
        }
        wezPoziome(bloczki.wiersz, elementy);
        if(czyDanaWartoscJestJuzWTablicy(elementy, i, LINIE)){
            continue;
        }
        wezPionowe(bloczki.kolumna, elementy);
        if(czyDanaWartoscJestJuzWTablicy(elementy, i, LINIE)){
            continue;
        }
        wezKwadrat(bloczki.malyKwadratSudoku, elementy);
        if(czyDanaWartoscJestJuzWTablicy(elementy, i, LINIE)){
            continue;
        }
        niewiadoma[rzeczywistyIndeks]=i;
        if(indeks==(MAXILOSC-1) || ustawWartosci((indeks+1), 0)){
            return 1;
        }
    }
    niewiadoma[rzeczywistyIndeks]=0;
    return 0;
}

void wezZPowrotem(int iloscNieustawionych){
    ogolnyLicznikNieustawionych++;
    int zmiennaPomocnicza=niewiadoma[indeksy[MAXILOSC-iloscNieustawionych]];
    if(!ustawWartosci((MAXILOSC-iloscNieustawionych), zmiennaPomocnicza)){
        nierozwiazane[indeksy[MAXILOSC-iloscNieustawionych]]=0;
        wezZPowrotem(++iloscNieustawionych);
    }
    else{
        niewiadoma[indeksy[MAXILOSC-iloscNieustawionych]]=zmiennaPomocnicza;
        for(int i=1; i<iloscNieustawionych; i++){
            niewiadoma[indeksy[MAXILOSC-iloscNieustawionych+i]]=0;
        }
        for(int i=(MAXILOSC-iloscNieustawionych); i>0; i--){
            indeksy[i]=indeksy[i-1];
        }
        indeksy[0]=zmiennaPomocnicza;
        if(ogolnyLicznikNieustawionych<MAXILOSC){
            wezZPowrotem(iloscNieustawionych);
        }
    }
}

void poczatkowoUstawWartosciNaZero(void){
    for(int i=0; i<MAXILOSC; i++){
        niewiadoma[i]=0;
    }
}

void losujDlaCiekawszegoUstawieniaWartosci(int losowa, int tablica1[], int tablica2[]){
    switch(losowa){
    case 1:
        tablica1[0]=2;
        tablica1[1]=1;
        tablica1[2]=0;
        break;
    case 2:
        tablica2[0]=2;
        tablica2[1]=1;
        tablica2[2]=0;
        break;
    case 3:
        tablica1[0]=2;
        tablica1[1]=1;
        tablica1[2]=0;
        tablica2[0]=2;
        tablica2[1]=1;
        tablica2[2]=0;
        break;
    }
}

void wypiszNaEkranIPytajOZapisDoPliku(void){
    char wyswietlenieRozwiazania, czyZapisacPlanszeDoPliku, czyZapisacRozwiazanieDoPliku;
    printf("\n***Program generuje plansze sudoku***\n");
    printf("Wcisnij enter, aby wygenerowac plansze.\n");
    getc(stdin);
    printf("\n\tTWOJA PLANSZA SUDOKU:\n");
    pokazPlanszeSudoku(nierozwiazane);
    fflush(stdin);
    printf("\n\n\nCzy wyswietlic rozwiazanie na ekranie?\nWpisz t, jesli tak: ");
    wyswietlenieRozwiazania=getc(stdin);
    if(tolower(wyswietlenieRozwiazania)=='t'){
        printf("\n\n\tROZWIAZANA PLANSZA SUDOKU:\n");
        pokazPlanszeSudoku(rozwiazane);
    }
    printf("\n\nCzy zapisac plansze do pliku? Wpisz t jesli tak: ");
    fflush(stdin);
    czyZapisacPlanszeDoPliku=getc(stdin);
    if(tolower(czyZapisacPlanszeDoPliku)=='t'){
        printf("Plansza zostanie zapisana w pliku sudoku.txt\n");
        printf("\nCzy zapisac tez rozwiazanie do innego pliku? Wpisz t, jesli tak: ");
        fflush(stdin);
        czyZapisacRozwiazanieDoPliku=getc(stdin);
        if(tolower(czyZapisacRozwiazanieDoPliku)=='t'){
            printf("Rozwiazanie zostanie zapisane w pliku rozwiazanie.txt\n");
            freopen("sudoku.txt", "w", stdout);     //niestandardowa funkcja
            printf("\n\n\tTWOJA PLANSZA SUDOKU:\n");
            pokazPlanszeSudoku(nierozwiazane);
            fclose(stdout);
            freopen("rozwiazanie.txt", "w", stdout);
            printf("\n\n\tROZWIAZANA PLANSZA SUDOKU:\n");
            pokazPlanszeSudoku(rozwiazane);
            fclose(stdout);
        }
        else{
            freopen("sudoku.txt", "w", stdout);
            printf("\n\n\tTWOJA PLANSZA SUDOKU:\n");
            pokazPlanszeSudoku(nierozwiazane);
            fclose(stdout);
        }
    }
}
