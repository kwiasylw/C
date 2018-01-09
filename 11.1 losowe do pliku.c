#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    FILE *out;
    int i, n;
    char filename[20];
    srand(time(0));
    printf("Program generuje wybrana ilosc liczb calkowitych i zapisuje je do wybranego pliku\n");
    printf("Podaj ilosc liczb do wygenerowania: ");
    scanf("%d", &n);
    if (n<1){
        printf("ERROR\nWprowadzona bledna wartosc\n");
    }
    else{
        printf("Podaj nazwe pliku: ");
        scanf("%s",filename);
        out = fopen(filename,"w");

        if (out) {
        for(i=0;i<n;++i) {
            fprintf(out,"%d\n",rand()%1000);
        }
        printf("Dane zostaly zapisane w wybranym pliku.");
        fclose(out);
        }
        else{
            printf("ERROR\nWprowadzona bledna nazwe\n");
            exit(1);
        }
    }
    return 0;
}
