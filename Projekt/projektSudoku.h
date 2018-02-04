#ifndef PROJEKTSUDOKU
#define PROJEKTSUDOKU_H

#define MAXILOSC 81
#define LINIE 9
#define LINIEWCZESCI 3


int indeksy[MAXILOSC];
int niewiadoma[MAXILOSC];
int rozwiazane[MAXILOSC];
int nierozwiazane[MAXILOSC];

struct czesciSkladowePlanszy{
    int wiersz;
    int kolumna;
    int malyKwadratSudoku; //kwadrat 3x3, cala plansza to 9 takich kwadratow
};

void pokazPlanszeSudoku(int*);
struct czesciSkladowePlanszy pobierzCzesci(int);
int czyDanaWartoscJestJuzWTablicy(int*, int, int);
void wezPoziome(int, int*);
void wezPionowe(int, int*);
void wezKwadrat(int, int*);
int ustawWartosci(int, int);
void wezZPowrotem(int);
void poczatkowoUstawWartosciNaZero(void);
void losujDlaCiekawszegoUstawieniaWartosci(int, int [], int []);
void wypiszNaEkranIPytajOZapisDoPliku(void);

#endif
