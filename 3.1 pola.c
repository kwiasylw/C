#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int sprawdzCzyNieujemnaWartosc(double);
int wybierzPoleLubObwod(void);
int sprawdzCzyTrojkatOTakichBokachIstnieje(double, double, double);
void obliczeniaDlaKwadratu(void);
void obliczeniaDlaProstokata(void);
void obliczeniaDlaTrojkata(void);
void obliczeniaDlaKola(void);


void obliczeniaDlaKwadratu(void){
    const double aKwadrat;
    printf("Wpisz dlugosc boku kwadratu: ");
    scanf("%lf", &aKwadrat);
    if(sprawdzCzyNieujemnaWartosc(aKwadrat)){
        printf("Podano bledna wartosc\n\n");
        obliczeniaDlaKwadratu();
    }
    
    int wyborDzialania=wybierzPoleLubObwod();
    if(wyborDzialania==1){
        printf("\nPole kwadratu wynosi %.2f\n\n", aKwadrat*aKwadrat);
    }
    if(wyborDzialania==2){
        printf("\nObwod kwadratu wynosi %.2f\n\n", 4*aKwadrat);
    }
}

void obliczeniaDlaProstokata(void){
    const double aProstokat, bProstokat;
    printf("Wpisz dlugosci pierwszego i drugiego boku prostokata: ");
    scanf("%lf %lf", &aProstokat, &bProstokat);
    if(sprawdzCzyNieujemnaWartosc(aProstokat) && sprawdzCzyNieujemnaWartosc(bProstokat)){
        printf("Podano bledna wartosc\n\n");
        obliczeniaDlaKwadratu();
    }
    
    int wyborDzialania=wybierzPoleLubObwod();
    if(wyborDzialania==1){
        printf("\nPole prostokata wynosi %.2f\n\n", aProstokat*bProstokat);
    }
    if(wyborDzialania==2){
        printf("\nObwod prostokata = %.2f\n\n", 2*(aProstokat+bProstokat));
    }
}

void obliczeniaDlaTrojkata(void){
    const double aTrojkat, bTrojkat, cTrojkat, wysokoscTrojkata;
    int licznikDoBlednychWartosci=0;
    printf("Podaj dlugosci trzech bokow trojkata (rozdzielone spacja):");
    scanf("%lf %lf %lf", &aTrojkat, &bTrojkat, &cTrojkat);
    printf("Podaj dlugosc wysokosci trojkata: ");
    scanf("%lf", &wysokoscTrojkata);
    printf("\n");
    
    licznikDoBlednychWartosci+=sprawdzCzyNieujemnaWartosc(aTrojkat)+sprawdzCzyNieujemnaWartosc(bTrojkat)+sprawdzCzyNieujemnaWartosc(cTrojkat);
    licznikDoBlednychWartosci+=sprawdzCzyNieujemnaWartosc(wysokoscTrojkata);
    licznikDoBlednychWartosci+=sprawdzCzyTrojkatOTakichBokachIstnieje(aTrojkat, bTrojkat, cTrojkat);
    if(licznikDoBlednychWartosci){
        printf("Trojkat o takich bokach nie istnieje lub podano ujemne wartosci. \nZacznijmy jeszcze raz.\n\n");
        obliczeniaDlaTrojkata();
    }
    
    int wyborDzialania=wybierzPoleLubObwod();
    if(wyborDzialania==1){
        printf("\nPole trojkata wynosi %.2f\n\n", aTrojkat*wysokoscTrojkata/2);
    }
    if(wyborDzialania==2){
        printf("\nObwod trojkata wynosi %.2f\n\n", aTrojkat+bTrojkat+cTrojkat);
    }
}

void obliczeniaDlaKola(void){
    const double r;
    printf("Podaj dlugosc promienia kola: ");
    scanf("%lf", &r);
    sprawdzCzyNieujemnaWartosc(r);
    
    int wyborDzialania=wybierzPoleLubObwod();
    if(wyborDzialania==1){
        printf("\nPole kola wynosi %.2f\n\n", M_PI*r*r);
    }
    if(wyborDzialania==2){
        printf("\nObwod kola wynosi %.2f\n\n", 2*M_PI*r);
    }
}

int wybierzPoleLubObwod(void){
    const int wyborDzialania;
    printf("\nWybierz, co chcesz obliczyc:\n\t1: pole\n\t2: obwod\n");
    printf("\nObliczam: ");
    scanf("%d", &wyborDzialania);
    if((wyborDzialania!=1) && (wyborDzialania!=2)){
        printf("Wpisano zla wartosc\n");
        wybierzPoleLubObwod();
    }
    return wyborDzialania;
}

int sprawdzCzyNieujemnaWartosc(double a){
    return a<=0;
}

int sprawdzCzyTrojkatOTakichBokachIstnieje(double a, double b, double c){
    if((a+b>c) && (b+c>a) && (a+c>b)){
        return 0;
    }
    else{
        return 1;
    }
}

int main(void){
    int wyborFigury;
    printf("\nProgram oblicza pola lub obwody figur geometrycznych: \n");
    printf("\t1: kwadrat\n\t2: prostokat\n\t3: trojkat\n\t4: kolo \n");
    printf("\nWpisz swoj wybor: ");
    scanf("%d", &wyborFigury);
    switch (wyborFigury){
        case 1:
            obliczeniaDlaKwadratu();
            break;
        case 2:
            obliczeniaDlaProstokata();
            break;
        case 3:
            obliczeniaDlaTrojkata();
            break;
        case 4:
            obliczeniaDlaKola();
            break;
        }
    return 0;
}
