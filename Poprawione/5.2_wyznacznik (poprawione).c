#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieWartosci(int n, int a[n][n]){
    srand(time(NULL));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            a[i][j]=rand()%10;
        }
    }
}

void wypisywanieMacierzy(int n,int a[n][n]){
    for(int i=0;i<n;++i){
        printf("\n");
        for(int j=0;j<n;++j){
            printf("%d\t",a[i][j]);
        }
    }
}

void obliczanieWyznacznika(int n, int a[n][n]){
    int wyznacznik;
    wyznacznik=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]-a[0][2]*a[1][1]*a[2][0]-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2];
    printf("\n\nWyznacznik tej macierzy 3x3 wynosi: %d\n\n",wyznacznik);
}


int main(){
    int a[3][3];
    printf("Program oblicza wyznacznik macierzy 3x3 o losowo wybranych wartosciach.\n");
    losowanieWartosci(3,a);
    printf("\nMacierz ma postac:");
    wypisywanieMacierzy(3,a);
    obliczanieWyznacznika(3,a);
    return 0;
}
