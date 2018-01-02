#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void losowanie(int a[10]){
    int i;
    srand(time(NULL));
    for(i=0;i<10;i++){
        a[i]=rand()%40;
    }
}

void wypisywanie(int a[10]){
    int i;
    losowanie(a);
    puts("\nTablica:");
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}

void srednia(int a[10]){
    int i;
    float wynik=0;
    for(i=0;i<10;i++){
        wynik+=a[i];
    }
    printf("\nSrednia elementow tablicy: %.2f\n",wynik/10);
}

void mediana(int a[10]){
    float mediana;
    int i,j,temp;
    losowanie(a);
    //sortowanie babelkowe
    for(i=0;i<9;i++){
        for(j=0;j<9-i;j++){
            if (a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    mediana=(a[4]+a[5])/2;
    printf("\nMediana elementow tablicy: %.2f",mediana);

}

void minMax(int a[10]){
    int min=a[0];
    int max=a[0];
    int i,j;
    for(i=0;i<10;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    for(i=0;i<10;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    printf("\nElement minimalny: %d\nElement maksymalny: %d",min,max);
    }


int main(int argc, char *argv[]){
    int a[10];
    int wybor;
    puts("\t***MENU***\n");
    printf("1.Losowanie tablicy 10 liczb\n2.Wyswietlanie jej \
           \n3.Liczenie sredniej liczb\n4.Liczenie mediany liczb \
           \n5.Maksymalny/minimalny element tablicy \n6.Wyjscie");
    while(1){
        printf("\n\nWpisz liczbe od 1 do 6: ");
        scanf("%d",&wybor);
        switch(wybor){
            case 1:
                losowanie(a);
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
