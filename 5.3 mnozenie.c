#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanieWartosci(int n, int k, int macierz1[n][k], int macierz2[n][k]){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            macierz1[i][j]=(-100)+rand()%200;
            macierz2[i][j]=(-100)+rand()%200;
        }
    }
}

void dwieMacierze2x2NaJednaMacierz2x2x2(int n, int k, int l, int macierz1[n][k], int macierz2[n][k],int macierz3[n][k][l]){
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            macierz3[0][i][j]=macierz1[i][j];
            macierz3[1][i][j]=macierz2[i][j];
        }
    }
}

void jednaMacierz2x2x2NaDwieMacierze2x2(int n, int k, int l, int macierz3[n][k][l], int macierz1[n][k], int macierz2[n][k]){
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            macierz1[i][j]=macierz3[0][i][j];
            macierz2[i][j]=macierz3[1][i][j];
        }
    }
}

void mnozenieOrazWypisywanieMacierzyWynikowej (int n, int k, int l, int macierz[n][k][l]){
    int macierz1[n][k], macierz2[n][k], wynikJako2x2[n][k];
    jednaMacierz2x2x2NaDwieMacierze2x2(2, 2, 2, macierz, macierz1, macierz2);
    for (int i=0; i<n; i++){
        wynikJako2x2[0][i]= macierz1[0][0]*macierz2[0][i]+macierz1[0][1]*macierz2[1][i];
        printf("%d\t", wynikJako2x2[0][i]);
    }
    printf("\n");
    for (int j=0; j<k; j++){
        wynikJako2x2[1][j]= macierz1[1][0]*macierz2[0][j]+macierz1[1][1]*macierz2[1][j];
        printf("%d\t", wynikJako2x2[1][j]);
    }
}

int main(){
    int macierz3[2][2][2], macierz1[2][2], macierz2[2][2];
    losowanieWartosci(2, 2, macierz1, macierz2);
    dwieMacierze2x2NaJednaMacierz2x2x2(2, 2, 2, macierz1, macierz2,macierz3);
    printf("W wyniku mnozenia losowych macierzy powstaje macierz:\n\n");
    mnozenieOrazWypisywanieMacierzyWynikowej(2, 2, 2, macierz3);
    printf("\n\n");
    return 0;
}
