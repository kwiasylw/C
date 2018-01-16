#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie(int a[],int n){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        a[i]=rand()%40;
    }
    puts("Elementy tablicy zostaly wylosowane.");
}

void wypisywanie(int a[10]){
    losowanie(a, 10);
    puts("\nTablica:");
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
}

void srednia(int a[10]){
    float wynik=0;
    for(int i=0; i<10; i++){
        wynik+=a[i];
    }
    printf("\nSrednia elementow tablicy: %.2f\n", wynik/10);
}

void sortowanie(int a[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if (a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void mediana(int a[10]){
    float mediana;
    int i, j, temp;
    losowanie(a, 10);
    sortowanie(a, 10);
    mediana=(a[4]+a[5])/2;
    printf("\nMediana elementow tablicy: %.2f", mediana);

}

void minMax(int a[10]){
    int min=a[0];
    int max=a[0];
    int j;
    for(int i=0; i<10; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    for(int i=0; i<10; i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    printf("\nElement minimalny: %d\nElement maksymalny: %d",min,max);
    }


int main(void){
    int a[10];
    int wybor;
    puts("\t***MENU***\n");
    printf("1.Losowanie tablicy 10 liczb\n2.Wyswietlanie jej \
           \n3.Liczenie sredniej liczb\n4.Liczenie mediany liczb \
           \n5.Maksymalny/minimalny element tablicy \n6.Wyjscie");
    while(1){
        printf("\n\nWpisz liczbe od 1 do 6: ");
        scanf("%d", &wybor);
        switch(wybor){
            case 1:
                losowanie(a,10);
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
