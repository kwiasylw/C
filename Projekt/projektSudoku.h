#ifndef PROJEKTSUDOKU
#define PROJEKTSUDOKU_H

#define MAXILOSC 81
#define LINIE 9
#define LINIEWCZESCI 3


int indeksy[MAXILOSC];
int niewiadoma[MAXILOSC];
int rozwiazane[MAXILOSC];
int nierozwiazane[MAXILOSC];

typedef struct CzesciSkladowePlanszy{
    int wiersz;
    int kolumna;
    int malyKwadratSudoku;
}CzesciSkladowePlanszy;


CzesciSkladowePlanszy pobierzCzesci(int indeks);

void pokazPlanszeSudoku(int* rozwiazanie);
void wypiszNaEkranIPytajOZapisDoPliku(void);

void poczatkowoUstawWartosciNaZero(void);
int ustawWartosci(int indeks, int niedozwolonaWartosc);
int czyDanaWartoscJestJuzWTablicy(int* tablica, int wartosc, int dlugosc);
void wezZPowrotem(int iloscNieustawionych);
void czyszczenieBufora(void);

void losujDlaCiekawszegoUstawieniaWartosci(int losowa, int tablica1[], int tablica2[]);
void losujAbyUniknacPustychPolNaKoncu(int losowa, int tablicaPrzedLinearyzacja[LINIE][LINIE]);
void linearyzujCalosc(int tablica[LINIE][LINIE]);
void porzadkujKilkaTablic(int tablicaWierszyCalosci[], int tablicaKolumnCalosci[], int tablicaPrzedLinearyzacja[LINIE][LINIE]);

void wezPoziome(int wiersz, int* zwroc);
void wezPionowe(int kolumna, int* zwroc);
void wezKwadrat(int kolejne, int* zwroc);

#endif
