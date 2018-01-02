#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void macierz2x2Na2x2x2(int macierz1[2][2], int macierz2[2][2],int macierz3[2][2][2])
{
    int i,j;
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            macierz3[0][i][j]=macierz1[i][j];
            macierz3[1][i][j]=macierz2[i][j];
        }
    }
}

void macierz2x2x2_to_macierz2x2(int macierz3[2][2][2],int macierz1[2][2],int macierz2[2][2]){
    int i,j;
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            macierz1[i][j]=macierz3[0][i][j];
            macierz2[i][j]=macierz3[1][i][j];
        }
    }
}

void mnozenie(int macierz[2][2][2]){
    int macierz1[2][2];
    int macierz2[2][2];
    macierz2x2x2_to_macierz2x2(macierz,macierz1,macierz2);
    int i,j;
    int wynikJako2x2[2][2];

    printf("W wyniku mnozenia losowych macierzy powstaje macierz:\n\n");
    for (i=0;i<2;i++){
        wynikJako2x2[0][i]= macierz1[0][0]*macierz2[0][i] + macierz1[0][1]*macierz2[1][i];
        printf("%d\t", wynikJako2x2[0][i]);
    }
    printf("\n");
    for (j=0;j<2;j++){
        wynikJako2x2[1][j]= macierz1[1][0]*macierz2[0][j]+ macierz1[1][1]*macierz2[1][j];
        printf("%d\t", wynikJako2x2[1][j]);
    }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int i,j;
    int macierz3[2][2][2];
    int macierz1[2][2];
    int macierz2[2][2];

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            macierz1[i][j]=(-100)+rand()%200;
            macierz2[i][j]=(-100)+rand()%200;
        }
    }

    macierz2x2Na2x2x2(macierz1,macierz2,macierz3);
    mnozenie(macierz3);

printf("\n\n");
return 0;
}
