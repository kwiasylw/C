#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void KtoraSzalkaWyzej(int wagaLewa, int wagaPrawa){
    if (wagaLewa==wagaPrawa){
        printf("Szalki sa na rownym poziomie\n");
    }

    if (wagaLewa<wagaPrawa){
        printf("Pierwsza szalka jest wyzej\n\n\n");
    }

    else{
        printf("Druga szalka jest wyzej\n\n\n");
    }

}

int main(int argc, char* argv[]){

    srand(time(NULL));
    int wagi[9]={1,1,1,1,1,1,1,1,1};
    int losowa, i, liczba1, liczba2, wagaLewa, wagaPrawa;
    losowa= 1+ rand()%9;
    wagi[losowa]=2;

    printf("Zagadka:\n");
    printf("Mamy 9 kulek tak samo wygladajacych. 8 wazy tyle samo, 1 jest ciezsza. \nOdnajdz ciezsza kulke w 2 wazeniach.\n\n\n");

    printf("Ile kulek chcesz polozyc na pierwsza szalke?  ");
    scanf("%d",&liczba1);
    printf("Ile kulek chcesz polozyc na druga szalke?  ");
    scanf("%d",&liczba2);

    wagaLewa=0;
    wagaPrawa=0;

    if (liczba1+liczba2<=9){
         for (i=0;i<liczba1;i++){
            wagaLewa=wagaLewa+wagi[i];
        }
        for (i=liczba1;i<liczba1+liczba2;i++){
            wagaPrawa=wagaPrawa+wagi[i];
        }
        KtoraSzalkaWyzej(wagaLewa,wagaPrawa);


        int wybor;
    printf("Z ktorej grupy zwazyc kulki? \n \t1: wczesniej niewazone \n\t2: z lewej szalki\n\t3: z prawej szalki \n");
        scanf("%d",&wybor);

        int liczba11, liczba22;
        printf("Ile kulek ma byc na lewej szalce?\n");
        scanf("%d",&liczba11);
        printf("Ile kulek ma byc na prawej szalce?\n");
        scanf("%d",&liczba22);
        wagaLewa=0;
        wagaPrawa=0;

        if (wybor==1){
                if (liczba1+liczba11+liczba2+liczba22<=9){
                    for (i=liczba1+liczba2;i<liczba1+liczba2+liczba11;i++){
                        wagaLewa=wagaLewa+wagi[i];
                    }

                    for (i=liczba1+liczba2+liczba11;i<liczba1+liczba2+liczba11+liczba22;i++){
                        wagaPrawa=wagaPrawa+wagi[i];
                    }
                    KtoraSzalkaWyzej(wagaLewa,wagaPrawa);
                }

                else{
                    printf("Podano za duzo kulek\n");
                }

        }
        else if (wybor==2){
                if (liczba1+liczba11+liczba2+liczba22<=9){
                    for (i=0;i<liczba11;i++){
                        wagaLewa=wagaLewa+wagi[i];
                    }
                    for (i=liczba11;i<liczba11+liczba22;i++){
                        wagaPrawa=wagaPrawa+wagi[i];
                    }
                    KtoraSzalkaWyzej(wagaLewa,wagaPrawa);
                }
                else{
                    printf("Podano za duzo kulek\n");
                }

        }
        else if (wybor==3){
                if (liczba1+liczba11+liczba2+liczba22<=9){
                    for (i=liczba1;i<liczba1+liczba11;i++){
                        wagaLewa=wagaLewa+wagi[i];
                    }
                    for (i=liczba1+liczba11;i<liczba1+liczba11+liczba22;i++){
                        wagaPrawa=wagaPrawa+wagi[i];
                    }
                    KtoraSzalkaWyzej(wagaLewa,wagaPrawa);
                }
                else{
                    printf("Podano za duzo kulek\n");
                }

        }
    }
    else{
        printf("Podano za duzo kulek\n");
    }

    printf("Czy juz znasz odpowiedz?\n");
    return 0;
}
