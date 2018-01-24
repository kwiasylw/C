#include<stdio.h>
#include<math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float stopnieNaradiany(void){
    float stopnie, radiany;
    printf("\nWpisz kat w stopniach: ");
    scanf("%f", &stopnie);
    radiany=stopnie*M_PI/180;
    printf("Wartosc w radianach wynosi: %.3f\n\n", radiany);
}

float radianyNaStopnie(void){
    float radiany, stopnie;
    printf("\nWpisz kat w radianach: ");
    scanf("%f", &radiany);
    stopnie=radiany*180/M_PI;
    printf("Wartosc w stopniach wynosi: %.3f\n\n", stopnie);
}

int main(void){
    int wyjscie=0, opcja=0;
    printf("Konwerter stopnie <-> radiany\n\n");
    while(wyjscie==0){
        printf("Wybierz jedna z ponizszych opcji: "
               "\n\t1: Zamiana stopni na radiany"
               "\n\t2: Zamiana radianyianow na stopnie"
               "\n\t3: Wyjscie"
               "\n\nWybor: ");
        scanf("%d", &opcja);
        switch(opcja){
            case 1:
                stopnieNaradiany();
                break;
            case 2:
                radianyNaStopnie();
                break;
            case 3:
                wyjscie=1;
                break;
            default:
                puts("\nWybrano zla opcje.\n");
                break;
        }
    }
    return 0;
}
