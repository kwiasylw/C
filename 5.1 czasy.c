#include <stdio.h>

enum IndeksCzasu{
    INDEKS_GODZINY=0,
    INDEKS_MINUTY=1,
    INDEKS_SEKUNDY=2
    };


void podawanieDanych(int n, int czas[n]){
    for(int i=0; i<n; ++i){
        printf("\t%d wartosc: ", i+1);
        scanf("%d", &czas[i]);
    }
}

int sprawdzPoprawnoscDanych(int godzina, int minuta, int sekunda){
    if((godzina>=0) && (godzina<=23) && (minuta>=0) && (minuta<=59) && (sekunda>=0) && (sekunda<=59)){
        return 0;
    }
    else{
        printf("\n\nZly zapis czasu.\n");
        return 1;
    }
}

int porownywanieCzasow(int n, int czas1[n], int czas2[n]){
    int j;
    if((sprawdzPoprawnoscDanych(czas1[INDEKS_GODZINY], czas1[INDEKS_MINUTY], czas1[INDEKS_SEKUNDY])) || (sprawdzPoprawnoscDanych(czas2[INDEKS_GODZINY], czas2[INDEKS_MINUTY], czas2[INDEKS_SEKUNDY]))){
        return 2;
    }
    else{
        for(int i=0; i<n; ++i){
            if(czas1[i]>czas2[i]){
                j=1;
                break;
            }
            if(czas1[i]<czas2[i]){
                j=-1;
                break;
            }
            else{
                j=0;
            }
        }
        return j;
    }
}

void wypisywanieWynikuPorownanZObjasnieniem(int wynik){
    if(wynik==-1){
        printf("%d, czyli czas pierwszy jest wczesniej.", wynik);
    }
    if(wynik==0){
        printf("%d, czyli czasy sa rowne.", wynik);
    }
    if(wynik==1){
        printf("%d, czyli czas drugi jest wczesniej.", wynik);
    }
}

int main(void){
    printf("Program porownuje dwie godziny\n\n");
    printf("Legenda: \n\t-1: czas drugi jest wczesniej \n\t 0: czasy sa rowne \n\t 1: czas drugi jest wczesniej\n\n\n");
    int czas1[3], czas2[3], wynik;
    PODAWANIE_DANYCH:
    printf("\nPodaj pierwsza godzine w formacie GG-MM-SS: \n");
    podawanieDanych(3, czas1);
    printf("\n\nPodaj druga godzine w formacie GG-MM-SS: \n");
    podawanieDanych(3, czas2);
    if(porownywanieCzasow(3, czas1, czas2)==2){
        goto PODAWANIE_DANYCH;
    }
    printf("\nWynik porownywania to: ");
    wypisywanieWynikuPorownanZObjasnieniem(porownywanieCzasow(3, czas1, czas2));
    printf("\n\n");
    return 0;
}
