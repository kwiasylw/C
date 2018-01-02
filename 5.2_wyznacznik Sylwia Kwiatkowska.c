#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a[3][3],i,j;
    srand(time(NULL));
    long wyznacznik;
    printf("Program oblicza wyznacznik macierzy 3x3 o losowo wybranych wartosciach.\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=rand()%10;
        }
    }

    printf("\nMacierz ma postac:");

    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++) {
            printf("%d\t",a[i][j]);
        }
    }

    wyznacznik=a[0][0]*((a[1][1]*a[2][2])-(a[2][1]*a[1][2]))-a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2])+a[0][2]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]);
    printf("\n\nWyznacznik tej macierzy 3x3 wynosi: %ld\n\n",wyznacznik);
    return 0;
}
