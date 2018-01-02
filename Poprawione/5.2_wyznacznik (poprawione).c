#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieWartosci(int a[3][3]){
    int i,j;
    srand(time(NULL));
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=rand()%10;
        }
    }
}

void wypisywanieMacierzy(int a[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("%d\t",a[i][j]);
        }
    }
}

void obliczanieWyznacznika(int a[3][3]){
    int wyznacznik;
    wyznacznik=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]-a[0][2]*a[1][1]*a[2][0]-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2];
    printf("\n\nWyznacznik tej macierzy 3x3 wynosi: %d\n\n",wyznacznik);
}


int main(){
    int a[3][3];
    printf("Program oblicza wyznacznik macierzy 3x3 o losowo wybranych wartosciach.\n");
    losowanieWartosci(a);
    printf("\nMacierz ma postac:");
    wypisywanieMacierzy(a);
    obliczanieWyznacznika(a);
    return 0;
}
