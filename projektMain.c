#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memcpy
#include <time.h>
#include "projektSudoku.h"


int main(void){
    srand(time(NULL));
    int i=0, j=0, zmiennaPomocnicza, tablicaPrzedLinearyzacja[LINIE][LINIE];
    int losowa=rand()%4;
    int tablicaWierszyCalosci[]={0, 1, 2}, tablicaKolumnCalosci[]={0, 1, 2};
    int wierszeCzesci, kolumnyCzesci, wierszeCalosci, kolumnyCalosci;
    int indeksWierszyCalosci, indeksKolumnCalosci, wartoscStartowa;

    poczatkowoUstawWartosciNaZero();
    losujDlaCiekawszegoUstawieniaWartosci(losowa, tablicaWierszyCalosci, tablicaKolumnCalosci);
    for(indeksWierszyCalosci=0; indeksWierszyCalosci<LINIEWCZESCI; indeksWierszyCalosci++){
        wierszeCalosci=tablicaWierszyCalosci[indeksWierszyCalosci];
        for(indeksKolumnCalosci=0; indeksKolumnCalosci<LINIEWCZESCI; indeksKolumnCalosci++){
            kolumnyCalosci=tablicaWierszyCalosci[indeksKolumnCalosci];
            wartoscStartowa=wierszeCalosci*LINIE*LINIEWCZESCI+(kolumnyCalosci*LINIEWCZESCI);
            for(wierszeCzesci=0; wierszeCzesci<LINIEWCZESCI; wierszeCzesci++){
                for(kolumnyCzesci=0; kolumnyCzesci<LINIEWCZESCI; kolumnyCzesci++){
                    tablicaPrzedLinearyzacja[i][j++]=wierszeCzesci*LINIE+kolumnyCzesci+wartoscStartowa;
                }
            }
            i++;
            j=0;
        }
    }
    for(i=0; i<LINIE; i++){
        for(j=0; j<LINIE; j++){
            losowa=rand()%LINIE;
            if(j==losowa){
                continue;
            }
            zmiennaPomocnicza=tablicaPrzedLinearyzacja[i][j];
            tablicaPrzedLinearyzacja[i][j]=tablicaPrzedLinearyzacja[i][losowa];
            tablicaPrzedLinearyzacja[i][losowa]=zmiennaPomocnicza;
        }
    }
    for(i=0; i<LINIE; i++){ //linearyzacja
        for(j=0; j<LINIE; j++){
            indeksy[i*LINIE+j]=tablicaPrzedLinearyzacja[i][j];
        }
    }
    ustawWartosci(0, 0);
    memcpy(rozwiazane, niewiadoma,(MAXILOSC*sizeof(int)));
    memcpy(nierozwiazane, niewiadoma,(MAXILOSC*sizeof(int)));
    wezZPowrotem(1);
    wypiszNaEkranIPytajOZapisDoPliku();
    return 0;
}
