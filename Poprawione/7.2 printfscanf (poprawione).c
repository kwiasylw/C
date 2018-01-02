#include <stdio.h>
#include <stdarg.h>

void funkcja1 (const char *tekst, va_list argumenty){
    printf("%s", tekst);
    char *wartosc;
    while (wartosc=va_arg(argumenty, char*)){
        if (wartosc=="%d"){
            scanf("%s",&wartosc);
        }
        printf("%s", wartosc);
    }
}

void funkcja2 (const char *tekst, ...) {
    va_list argumenty;
    va_start(argumenty, tekst);
    funkcja1 (tekst, argumenty);
    va_end (argumenty);
}

int main (int argc, char *argv[]) {
    funkcja2("Podaj ","dluzszy ","bok ","prostokata: ","%d","A"," teraz"," krotszy: ","%d",NULL);
    return 0;
}
