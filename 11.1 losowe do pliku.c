#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generowanieDoPliku(int n, const char* filename){
    FILE *out;
    srand(time(NULL));
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
        generowanieDoPliku(n, filename);

    }
}

int main(int argc, char *argv[]){
    printf("Program generuje wybrana ilosc liczb calkowitych i zapisuje je do wybranego pliku\n");
    int n=atoi(argv[1]);
    char* filename=argv[2];
    generowanieDoPliku(n, filename);
    getc(stdin);
    return 0;
}
