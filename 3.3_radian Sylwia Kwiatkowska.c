#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h> //do obslugi getch()


float StopnieNaRad(float stopnie)
{
    float rad=stopnie*M_PI/180;
    return rad;
}

float RadNaStopnie(float rad)
{
    float stopnie=rad*180/M_PI;
    return stopnie;
}

int main(void)
{
    int wyjscie=0, opcja=0;
    float stopnie=0, rad=0, kat=0;
    while (wyjscie==0){
        system("cls");
        printf("Konwerter stopnie <-> radiany\n\n");
        printf("Wybierz jedna z ponizszych opcji: "
               "\n\t1: Zamiana stopni na radiany"
               "\n\t2: Zamiana radianow na stopnie"
               "\n\t3: Wyjscie"
               "\n\nWybor: ");
        scanf("%d",&opcja);

        switch (opcja){
        case 1:
            printf("\nWpisz kat w stopniach: ");
            scanf("%f",&stopnie);
            kat=StopnieNaRad(stopnie);
            printf("Wartosc w radianach wynosi: %.3f",kat);
            getch();
            break;


        case 2:
            printf("\nWpisz kat w radianach: ");
            scanf("%f",&rad);
            kat=RadNaStopnie(rad);
            printf("Wartosc w stopniach wynosi: %.3f",kat);
            getch();
            break;


        case 3:
            wyjscie=1;
            break;


        default:
            printf("\nWybrano zla opcje. Wpisz ponownie");
            getch();
            break;
        }
    }

printf("\nNacisnij cokolwiek, aby zamknac program.");
getch();
return 0;
}

