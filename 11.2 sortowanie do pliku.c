#include <stdio.h>
#include <stdlib.h>


void generowanieDoPliku(int n, int tab[], const char* targetFilename){
    FILE *out=fopen(targetFilename, "w");
    if(out){
        fprintf(out,"Posortowane liczby:\n");
        for(int i=0; i<n; ++i){
            fprintf(out, "%d ", tab[i]);
        }
        printf("Zapisano do pliku %s\n", targetFilename);
        fclose(out);
    }
    else{
        printf("\nWprowadzona bledna nazwe pliku\n\n");
        exit(1);
    }
}

void sortowanie(int n, int tab[]){
    int temp;
    for(int i=0; i<n; ++i){
        for(int j=0; j<(n-1); ++j){
            if(tab[j]>tab[j+1]){
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

void pobieranieDanychZPlikuIZapisDoDrugiego(const char* sourceFilename, const char* targetFilename){
    FILE *in=fopen(sourceFilename, "r");
    int i=0, a, totalNum, tab[100];
    if(in){
        while(!feof(in)){
            fscanf(in, "%d ", &a);
            tab[i]=a;
            i++;
        }
        fclose(in);
        printf("Dane pobrano z pliku %s\n", sourceFilename);
        totalNum=i;
        sortowanie(totalNum, tab);
        generowanieDoPliku(totalNum, tab, targetFilename);
    }
    else{
        printf("\nWprowadzona bledna nazwe pliku\n\n");
        exit(1);
    }
}



int main(int argc, char *argv[]){
    printf("Program pobiera liczby z I programuje, sortuje je i zapisuje do II pliku.\n");
    const char* sourceFilename=argv[1];
    const char* targetFilename=argv[2];
    pobieranieDanychZPlikuIZapisDoDrugiego(sourceFilename, targetFilename);
    getc(stdin);
    return 0;
}
