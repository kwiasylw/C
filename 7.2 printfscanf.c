#include <stdio.h>
#include <stdarg.h>

void wypisywanieIProsbaOPodanieZnaku(const char *tekst, va_list argumenty){
    printf("%s", tekst);
    char *wartosc;
    while (wartosc=va_arg(argumenty, char*)){
        if (wartosc=="%d"){
            scanf("%s", &wartosc);
        }
        printf("%s", wartosc);
    }
}

void przyjmowanieNieokreslonejLiczbyArgumentow(const char *tekst, ...){
    va_list argumenty;
    va_start(argumenty, tekst);
    wypisywanieIProsbaOPodanieZnaku(tekst, argumenty);
    va_end(argumenty);
}

int main(void){
    przyjmowanieNieokreslonejLiczbyArgumentow("Podaj ", "dluzszy ", "bok ", "prostokata: ", "%d", "A", " teraz", " krotszy: ", "%d", NULL);
    return 0;
}
