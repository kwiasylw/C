#include <stdio.h>


void podawanieDanych(int, int[]);
void petlaDoPodawaniaDanych(int, int[], int[]);
int sprawdzPoprawnoscDanych(int, int, int);
int porownywanieCzasow(int, int[], int[]);
void wypisywanieWynikuPorownanZObjasnieniem(int);


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

void petlaDoPodawaniaDanych(int n, int czas1[], int czas2[]){
    printf("\nPodaj pierwsza godzine w formacie GG-MM-SS: \n");
    podawanieDanych(n, czas1);
    printf("\n\nPodaj druga godzine w formacie GG-MM-SS: \n");
    podawanieDanych(n, czas2);
    if(porownywanieCzasow(n, czas1, czas2)==2){
        petlaDoPodawaniaDanych(n, czas1, czas2);
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
    printf("\nWynik porownywania to: ");
    if(wynik==-1){
        printf("%d, czyli czas pierwszy jest wczesniej.\n\n", wynik);
    }
    if(wynik==0){
        printf("%d, czyli czasy sa rowne.\n\n", wynik);
    }
    if(wynik==1){
        printf("%d, czyli czas drugi jest wczesniej.\n\n", wynik);
    }
}

int main(void){
    printf("Program porownuje dwie godziny\n\n");
    printf("Legenda: \n\t-1: czas drugi jest wczesniej \n\t 0: czasy sa rowne \n\t 1: czas drugi jest wczesniej\n\n\n");
    int czas1[3], czas2[3], wynik;
    petlaDoPodawaniaDanych(3, czas1, czas2);
    wypisywanieWynikuPorownanZObjasnieniem(porownywanieCzasow(3, czas1, czas2));
    return 0;
}
