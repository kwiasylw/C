#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ILOSC 10


void losowanie(int a[]){
    srand(time(NULL));
    for(int i=0; i<ILOSC; i++){
        a[i]=rand()%40;
    }
}

void wypisywanie(int a[]){
    losowanie(a);
    puts("\nTablica:");
    for(int i=0; i<ILOSC; i++){
        printf("%d ", a[i]);
    }
}

void srednia(int a[]){
    float wynik=0;
    for(int i=0; i<ILOSC; i++){
        wynik+=a[i];
    }
    printf("\nSrednia elementow tablicy: %.2f\n", wynik/10);
}

void sortowanie(int a[]){
    int temp;
    for(int i=0; i<ILOSC; i++){
        for(int j=0; j<ILOSC-1-i; j++){
            if (a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void mediana(int a[]){
    float mediana;
    losowanie(a);
    sortowanie(a);
    mediana=(a[4]+a[5])/2;
    printf("\nMediana elementow tablicy: %.2f", mediana);
}

void minMax(int a[]){
    int min=a[0], max=a[0];
    for(int i=0; i<ILOSC; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    for(int i=0; i<ILOSC; i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    printf("\nElement minimalny: %d\nElement maksymalny: %d", min, max);
    }


int main(void){
    int a[10], wybor;
    puts("\t***MENU***\n");
    printf("1.Losowanie tablicy 10 liczb\n2.Wyswietlanie jej \
           \n3.Liczenie sredniej liczb\n4.Liczenie mediany liczb \
           \n5.Maksymalny/minimalny element tablicy \n6.Wyjscie");

    while(1){
        printf("\n\nWpisz liczbe od 1 do 6: ");
        scanf("%d", &wybor);
        switch(wybor){
            case 1:
                losowanie(a);
                puts("Elementy tablicy zostaly wylosowane.");
                break;
            case 2:
                wypisywanie(a);
                break;
            case 3:
                wypisywanie(a);
                srednia(a);
                break;
            case 4:
                wypisywanie(a);
                mediana(a);
                break;
            case 5:
                wypisywanie(a);
                minMax(a);
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
