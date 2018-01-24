#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ILOSCKULEK 9

void ktoraSzalkaWyzej(int wagaLewa, int wagaPrawa){
    if(wagaLewa==wagaPrawa){
        printf("Szalki sa na rownym poziomie\n\n");
    }
    else if(wagaLewa<wagaPrawa){
        printf("Pierwsza szalka jest wyzej\n\n");
    }
    else{
        printf("Druga szalka jest wyzej\n\n");
    }
}

int sumowanieWagNaSzalkach(int k, int m, int n, int wagaLewa, int wagaPrawa, int wagi[]){
    for(int i=k; i<m; i++){
        wagaLewa+=wagi[i];
    }
    for(int i=m; i<m+n; i++){
        wagaPrawa+=wagi[i];
    }
}

int pobieranieIlosciKulekNaSzalceOdUzytkownika(int n){
    int liczba;
    printf("Ile kulek chcesz polozyc na %d. szalke?  ", n);
    scanf("%d", &liczba);
    return liczba;
}

int sprawdzenieCzyNiePodanoZaDuzoKulek(int liczba1, int liczba2, int liczba3, int liczba4){
    if(liczba1+liczba2+liczba3+liczba4<=ILOSCKULEK){
        return 0;
    }
    else{
        printf("Podano za duzo kulek\n\n\n");
        return 1;
    }
}

void pierwszeSzacowanieWag(int liczba1, int liczba2, int wagaLewa, int wagaPrawa, int wagi[]){
    while(sprawdzenieCzyNiePodanoZaDuzoKulek(liczba1, liczba2, 0, 0)){
        liczba1=pobieranieIlosciKulekNaSzalceOdUzytkownika(1);
        liczba2=pobieranieIlosciKulekNaSzalceOdUzytkownika(2);
    }
    sumowanieWagNaSzalkach(0, liczba1, liczba2, wagaLewa, wagaPrawa, wagi);
    ktoraSzalkaWyzej(wagaLewa, wagaPrawa);
}

void drugieSzacowanieWag(int liczba1, int liczba2, int liczba11, int liczba22, int wagaLewa, int wagaPrawa, int wagi[]){
    int wybor;
    wagaLewa=0, wagaPrawa=0;
    printf("Z ktorej grupy zwazyc kulki? \n \t1: wczesniej niewazone \n\t2: z lewej szalki\n\t3: z prawej szalki \n");
    scanf("%d", &wybor);
    do{
        liczba11=pobieranieIlosciKulekNaSzalceOdUzytkownika(1);
        liczba22=pobieranieIlosciKulekNaSzalceOdUzytkownika(2);
    } while(sprawdzenieCzyNiePodanoZaDuzoKulek(liczba1, liczba11, liczba2, liczba22));

    if(wybor==1){
        sumowanieWagNaSzalkach(liczba1+liczba2, liczba1+liczba2+liczba11, liczba22, wagaLewa, wagaPrawa, wagi);
        ktoraSzalkaWyzej(wagaLewa, wagaPrawa);
    }
    else if(wybor==2){
        sumowanieWagNaSzalkach(0, liczba11, liczba22, wagaLewa, wagaPrawa, wagi);
        ktoraSzalkaWyzej(wagaLewa, wagaPrawa);
    }
    else if(wybor==3){
        sumowanieWagNaSzalkach(liczba1, liczba1+liczba11, liczba22, wagaLewa, wagaPrawa, wagi);
        ktoraSzalkaWyzej(wagaLewa, wagaPrawa);
    }
}

int main(void){
    srand(time(NULL));
    int losowa, liczba1, liczba2, liczba11, liczba22, wagaLewa=0, wagaPrawa=0;
    int wagi[9]={1, 1, 1, 1, 1, 1, 1, 1, 1};
    losowa=1+rand()%ILOSCKULEK;
    wagi[losowa]=2;
    printf("Zagadka:\n");
    printf("Mamy 9 kulek tak samo wygladajacych. 8 wazy tyle samo, 1 jest ciezsza. \nOdnajdz ciezsza kulke w 2 wazeniach.\n\n\n");
    liczba1=pobieranieIlosciKulekNaSzalceOdUzytkownika(1);
    liczba2=pobieranieIlosciKulekNaSzalceOdUzytkownika(2);
    pierwszeSzacowanieWag(liczba1, liczba2, wagaLewa, wagaPrawa, wagi);
    drugieSzacowanieWag(liczba1, liczba2, liczba11, liczba22, wagaLewa, wagaPrawa, wagi);
    printf("Czy juz znasz odpowiedz?\n");
    return 0;
}
