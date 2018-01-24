#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wybieranieIlosciLiczbDoWygenerowania(void){
    int x;
    printf("Podaj ilosc liczb do wygenerowania: ");
    scanf("%d", &x);
    if(x<1){
        printf("ERROR\nWprowadzona bledna wartosc\n\n\n");
        wybieranieIlosciLiczbDoWygenerowania();
    }
    else{
        return x;
    }
}

void generowanieDoPliku(int n){
    FILE *out;
    char filename[20];
    srand(time(NULL));
    printf("Podaj nazwe pliku: ");
    scanf("%s", filename);
    out=fopen(filename, "w");
    if(out){
        for(int i=0; i<n; ++i){
            fprintf(out, "%d ", rand()%1000);
        }
        printf("Dane zostaly zapisane w wybranym pliku.\n");
        fclose(out);
    }
    else{
        printf("ERROR\nWprowadzona bledna nazwe\n");
        generowanieDoPliku(n);

    }
}

int main(void){
    printf("Program generuje wybrana ilosc liczb calkowitych i zapisuje je do wybranego pliku\n");
    int n=wybieranieIlosciLiczbDoWygenerowania();
    generowanieDoPliku(n);
    return 0;
}
