#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int randomowa = rand() % 10 + 1;
    int poprawne = 0;
    int liczbaUzytk;
    int licznik = 0;

    printf("Zgadnij liczbe wylosowana przez komputer! (Zakres od 1 do 10) ");
    printf("\nWpisz liczbe: ");

    do {
        scanf("%d", &liczbaUzytk);
        if ((liczbaUzytk>10)||(liczbaUzytk<1)){
            printf("*\n*\nWpisales liczbe spoza zakresu!!\n");
            printf("Twoja liczba zostanie zmodyfikowana, aby nalezala do danego zakresu");
            liczbaUzytk=(abs(liczbaUzytk))%10;
            printf("*\n*\nTeraz Twoja liczba to: %d\n\n",liczbaUzytk);
            }


        if (liczbaUzytk==randomowa){
            licznik++;
            printf("\nMasz racje! Komputer wylosowal liczbe %d. \nZgadles za %d razem, gratulacje!\n",randomowa,licznik);
            poprawne = 1;
        }

        if (liczbaUzytk<randomowa){
            licznik++;
            printf("\nWpisales za mala liczbe. Sprobuj jeszcze raz:  ");
        }

        if (liczbaUzytk>randomowa){
            licznik++;
            printf("\nWpisales za duza liczbe. Sprobuj jeszcze raz:  ");
        }
    } while (poprawne == 0);

    return 0;
}
