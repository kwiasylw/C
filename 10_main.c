#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void menu(Vector *vect){
    int wybor;
    printf("\n\tCo chcesz zrobic:\n");
    printf("1. Sprawdzic ilosc elementow.\n");
    printf("2. Sprawdzic ilosc zaalokowanej pamieci dla tablicy.\n");
    printf("3. Sprawdzic czy lista jest pusta.\n");
    printf("4. Dodac nowy element na koniec listy.\n");
    printf("5. Dodac element w konkretne miejsce.\n");
    printf("6. Usunac element.\n");
    printf("7. Odwrocic liste.\n");
    printf("8. Zwrocic N-ty element.\n");
    printf("9. Zakonczyc dzialanie programu.\n");
    printf("\n\nTWOJ WYBOR: ");
    scanf("%d",&wybor);
    switch(wybor){
        case 1:
            printf("\nAktualna ilosc elementow: %d\n\n",size(vect));
            return menu(vect);
            break;
        case 2:
            printf("\nAktualna ilosc zajetej pamieci: %d bit\n\n",capacity(vect));
            return menu(vect);
            break;
        case 3:
            empty(vect);
            return menu(vect);
            break;
        case 4:
            push_back(vect);
            return menu(vect);
            break;
        case 5:
            insert(vect);
            return menu(vect);
            break;
        case 6:
            removeElement(vect);
            return menu(vect);
            break;
        case 7:
            reverse(vect);
            return menu(vect);
            break;
        case 8:
            at(vect);
            return menu(vect);
            break;
        case 9:
            return;
            break;
        default:
            printf("Podano zla wartosc.\n");
            return menu(vect);
            break;
    }
}

int main(){
    Vector *vect=NULL;
    vect=reserve(vect); //jesli poda sie jako argument inna strukture Vector
    menu(vect);           //to funkcja przepisze elementy
    return 0;
}
