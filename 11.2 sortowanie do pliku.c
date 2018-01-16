#include <stdio.h>
#include <stdlib.h>


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
    FILE *in, *out;
    int i=0,totalNum,tab[100];
    char line[100],filename1[20],filename2[20];
    printf("Program pobiera liczby z I programuje, sortuje je i zapisuje do II pliku.\n\n");
    printf("Podaj nazwe pliku do pobrania danych: ");
    scanf("%s", filename1);
    printf("\nPodaj nazwe pliku docelowego: ");
    scanf("%s", filename2);
    in=fopen(filename1, "r");
    out=fopen(filename2, "w");
    if((in) && (out)){
        while(fgets(line, sizeof line, in)!=NULL) {
            tab[i]=atoi(line);
            i++;
        }
        totalNum=i;
        sortowanie(totalNum,tab);
        fprintf(out,"Posortowane liczby:\n");
        for(i=0; i<totalNum; ++i){
            fprintf(out, "%d\n", tab[i]);
        }
        printf("Dane zostaly zapisane w wybranym pliku.");
        fclose(in);
        fclose(out);
    }
    else{
        printf("\nERROR\nWprowadzona bledna nazwe\n");
        exit(1);
    }
    return 0;
}
