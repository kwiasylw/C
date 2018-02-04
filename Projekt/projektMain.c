#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projektSudoku.h"


int main(void){
    srand(time(NULL));
    int losowa=rand()%4, tablicaPrzedLinearyzacja[LINIE][LINIE];
    int tablicaWierszyCalosci[]= {0, 1, 2}, tablicaKolumnCalosci[]= {0, 1, 2};
    poczatkowoUstawWartosciNaZero();

    losujDlaCiekawszegoUstawieniaWartosci(losowa, tablicaWierszyCalosci, tablicaKolumnCalosci);
    porzadkujKilkaTablic(tablicaWierszyCalosci, tablicaKolumnCalosci, tablicaPrzedLinearyzacja);
    losujAbyUniknacPustychPolNaKoncu(losowa, tablicaPrzedLinearyzacja);
    linearyzujCalosc(tablicaPrzedLinearyzacja);

    ustawWartosci(0, 0);
    memcpy(rozwiazane, niewiadoma, (MAXILOSC*sizeof(int)));
    memcpy(nierozwiazane, niewiadoma, (MAXILOSC*sizeof(int)));
    wezZPowrotem(1);
    wypiszNaEkranIPytajOZapisDoPliku();
    return 0;
}
