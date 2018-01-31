#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sprawdzenieCzyPodanoOdpowiedniaIloscLiczbDoWygenerowania(int n){
    if(n<1){
        printf("Wprowadzona bledna ilosc liczb, dane nie zostana wygenerowane\n\n\n");
        exit(1);
    }
    else{
       printf("Ilosc liczb do wygenerowania to: %d\n", n);
    }
}

void generowanieDoPliku(int n, const char* filename){
    FILE *out;
    srand(time(NULL));
    out=fopen(filename, "w");
    if(out){
        for(int i=0; i<n; ++i){
            fprintf(out, "%d ", rand()%1000);
        }
        printf("Dane zostaly zapisane w  pliku: %s.\n", filename);
        fclose(out);
    }
    else{
        printf("ERROR\nWprowadzona bledna nazwe\n");
        generowanieDoPliku(n, filename);

    }
}

int main(int argc, char *argv[]){
    printf("Program generuje wybrana ilosc liczb calkowitych i zapisuje je do wybranego pliku\n");
    int n=atoi(argv[1]);
    char* filename=argv[2];
    sprawdzenieCzyPodanoOdpowiedniaIloscLiczbDoWygenerowania(n);
    generowanieDoPliku(n, filename);
    getc(stdin);
    return 0;
}
