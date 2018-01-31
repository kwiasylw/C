#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int zakresOd=1, zakresDo=10;

int sprawdzenieIKorygowanieLiczby(int liczba, int zakresDo, int zakresOd){
    if((liczba>zakresDo) || (liczba<zakresOd)){
            printf("*\n*\nWpisales liczbe spoza zakresu!!\n");
            printf("Twoja liczba zostanie zmodyfikowana, aby nalezala do danego zakresu\n");
            liczba=(abs(liczba))%10;
            printf("*\n*\nTeraz Twoja liczba to: %d\n\n", liczba);
        }
    return liczba;
}

int main(void){
    srand(time(NULL));
    int randomowa=rand()%10+1;
    int poprawne=0, liczbaProbGracza=0, liczbaWybranaPrzezGracza;
    printf("Zgadnij liczbe wylosowana przez komputer! (Zakres od %d do %d) ", zakresOd, zakresDo);
    printf("\nWpisz liczbe: ");
    do{
        scanf("%d", &liczbaWybranaPrzezGracza);
        liczbaWybranaPrzezGracza=sprawdzenieIKorygowanieLiczby(liczbaWybranaPrzezGracza, zakresDo, zakresOd);
        if(liczbaWybranaPrzezGracza==randomowa){
            printf("\nMasz racje! Komputer wylosowal liczbe %d. \nZgadles za %d razem, gratulacje!\n", randomowa, liczbaProbGracza+1);
            break;
        }
        if(liczbaWybranaPrzezGracza<randomowa){
            printf("\nWpisales za mala liczbe. Sprobuj jeszcze raz:  ");
        }
        if(liczbaWybranaPrzezGracza>randomowa){
            printf("\nWpisales za duza liczbe. Sprobuj jeszcze raz:  ");
        }
        liczbaProbGracza++;
    } while (poprawne==0);
    return 0;
}
