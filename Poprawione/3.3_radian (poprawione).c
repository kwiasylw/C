#include<stdio.h>
#include<math.h>

float stopnieNaRad(void){
    float stopnie;
    printf("\nWpisz kat w stopniach: ");
    scanf("%f",&stopnie);
    stopnie=stopnie*M_PI/180;
    printf("Wartosc w radianach wynosi: %.3f\n\n",stopnie);
}

float radNaStopnie(void){
    float rad;
    printf("\nWpisz kat w radianach: ");
    scanf("%f",&rad);
    rad=rad*180/M_PI;
    printf("Wartosc w stopniach wynosi: %.3f\n\n",rad);
}

int main(void){
    int wyjscie=0,opcja=0;
    printf("Konwerter stopnie <-> radiany\n\n");
    while (wyjscie==0){
        printf("Wybierz jedna z ponizszych opcji: "
               "\n\t1: Zamiana stopni na radiany"
               "\n\t2: Zamiana radianow na stopnie"
               "\n\t3: Wyjscie"
               "\n\nWybor: ");
        scanf("%d",&opcja);
        switch (opcja){
        case 1:
            stopnieNaRad();
            break;

        case 2:
            radNaStopnie();
            break;

        case 3:
            wyjscie=1;
            break;

        default:
            puts("\nWybrano zla opcje. ");
            break;
        }
    }
    return 0;
}

