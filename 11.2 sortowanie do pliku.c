#include <stdio.h>
#include <stdlib.h>


void pobieranieDanychZPlikuIZapisDoDrugiego(void);
void generowanieDoPliku(int, int[]);
void sortowanie(int, int[]);


void pobieranieDanychZPlikuIZapisDoDrugiego(void){
    FILE *in;
    int i=0, a, totalNum, tab[100];
    char  filename[20];
    printf("Podaj nazwe pliku do pobrania danych: ");
    scanf("%s", filename);
    in=fopen(filename, "r");
    if(in){
        while(!feof(in)){
            fscanf(in, "%d ", &a);
            tab[i]=a;
            i++;
        }
        fclose(in);
        totalNum=i;
        sortowanie(totalNum, tab);
        generowanieDoPliku(totalNum, tab);
    }
    else{
        printf("\nERROR\nWprowadzona bledna nazwe\n\n");
        pobieranieDanychZPlikuIZapisDoDrugiego();
    }
}

void generowanieDoPliku(int n, int tab[]){
    FILE *out;
    char filename[20];
    printf("Podaj nazwe pliku docelowego: ");
    scanf("%s", filename);
    out=fopen(filename, "w");
    if (out){
        fprintf(out,"Posortowane liczby:\n");
        for(int i=0; i<n; ++i){
            fprintf(out, "%d ", tab[i]);
        }
        printf("Dane zostaly zapisane w wybranym pliku.\n");
        fclose(out);
    }
    else{
        printf("ERROR\nWprowadzona bledna nazwe\n\n");
        generowanieDoPliku(n, tab);
    }
}

void sortowanie(int n, int tab[]){
    int temp;
    for (int i=0; i<n; ++i) {
        for(int j=0; j<(n-1); ++j){
            if(tab[j]>tab[j+1]){
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

int main(){
    printf("Program pobiera liczby z I programuje, sortuje je i zapisuje do II pliku.\n\n");
    pobieranieDanychZPlikuIZapisDoDrugiego();
    return 0;
}
