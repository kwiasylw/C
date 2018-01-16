#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int randomowa=rand()%10+1;
    int poprawne=0,licznik=0,liczbaUzytk;
    int zakresOd=1,zakresDo=10;
    printf("Zgadnij liczbe wylosowana przez komputer! (Zakres od 1 do 10) ");
    printf("\nWpisz liczbe: ");
    do{
        scanf("%d", &liczbaUzytk);
        if ((liczbaUzytk>zakresDo)||(liczbaUzytk<zakresOd)){
            printf("*\n*\nWpisales liczbe spoza zakresu!!\n");
            printf("Twoja liczba zostanie zmodyfikowana, aby nalezala do danego zakresu\n");
            liczbaUzytk=(abs(liczbaUzytk))%10;
            printf("*\n*\nTeraz Twoja liczba to: %d\n\n",liczbaUzytk);
        }
        if (liczbaUzytk==randomowa){
            licznik++;
            printf("\nMasz racje! Komputer wylosowal liczbe %d. \nZgadles za %d razem, gratulacje!\n",randomowa,licznik);
            poprawne=1;
            break;
        }
        if (liczbaUzytk<randomowa){
            licznik++;
            printf("\nWpisales za mala liczbe. Sprobuj jeszcze raz:  ");
        }
        if (liczbaUzytk>randomowa){
            licznik++;
            printf("\nWpisales za duza liczbe. Sprobuj jeszcze raz:  ");
        }
    } while (poprawne==0);
    return 0;
}
