#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sprawdzCzyNieujemnaWartosc(double);
int coObliczyc(void);
int sprawdzCzyTrojkatOTakichBokachIstnieje(double,double,double);
void obliczeniaDlaKwadratu(void);
void obliczeniaDlaProstokata(void);
void obliczeniaDlaTrojkata(void);
void obliczeniaDlaKola(void);


void obliczeniaDlaKwadratu(void){
    const double aKwadrat;
    printf("Wpisz dlugosc boku kwadratu: ");
    scanf("%lf",&aKwadrat);
    sprawdzCzyNieujemnaWartosc(aKwadrat);
    int wyborDzialania=coObliczyc();
    if (wyborDzialania==1){
        double poleKwadratu=aKwadrat*aKwadrat;
        printf("\nPole kwadratu wynosi %.2lf\n\n",poleKwadratu);
    }
    if (wyborDzialania==2){
        double obwodKwadratu=4*aKwadrat;
        printf("\nObwod kwadratu wynosi %.2lf\n\n",obwodKwadratu);
    }
}

void obliczeniaDlaProstokata(void){
    const double aProstokat, bProstokat;
    printf("Wpisz dlugosci pierwszego i drugiego boku prostokata: ");
    scanf("%lf %lf",&aProstokat,&bProstokat);
    sprawdzCzyNieujemnaWartosc(aProstokat);
    sprawdzCzyNieujemnaWartosc(bProstokat);
    int wyborDzialania=coObliczyc();
    if (wyborDzialania==1){
        double poleProstokata=aProstokat*bProstokat;
        printf("\nPole prostokata wynosi %.2lf\n\n",poleProstokata);
    }
    if (wyborDzialania==2){
        double obwodProstokata=2*(aProstokat+bProstokat);
        printf("\nObwod prostokata = %.2lf\n\n",obwodProstokata);
    }
}

void obliczeniaDlaTrojkata(void){
    const double aTrojkat, bTrojkat, cTrojkat, wysokoscTrojkata;
    int licznikDoBlednychWartosci=0;
    printf("Podaj dlugosci trzech bokow trojkata (rozdzielone spacja):");
    scanf("%lf %lf %lf",&aTrojkat,&bTrojkat,&cTrojkat);
    printf("Podaj dlugosc wysokosci trojkata: ");
    scanf("%lf",&wysokoscTrojkata);
    printf("\n");
    licznikDoBlednychWartosci+=sprawdzCzyNieujemnaWartosc(aTrojkat)+sprawdzCzyNieujemnaWartosc(bTrojkat)+sprawdzCzyNieujemnaWartosc(cTrojkat);
    licznikDoBlednychWartosci+=sprawdzCzyNieujemnaWartosc(wysokoscTrojkata);
    licznikDoBlednychWartosci+=sprawdzCzyTrojkatOTakichBokachIstnieje(aTrojkat, bTrojkat, cTrojkat);
    if(licznikDoBlednychWartosci){
        printf("Trojkat o takich bokach nie istnieje lub podano ujemne wartosci. \nZacznijmy jeszcze raz.\n\n");
        obliczeniaDlaTrojkata();
    }
    int wyborDzialania=coObliczyc();
    if (wyborDzialania==1){
        double poleTrojkata=aTrojkat*wysokoscTrojkata/2;
        printf("\nPole trojkata wynosi %.2lf\n\n",poleTrojkata);
    }
    if (wyborDzialania==2){
        double obwoTrojkata=aTrojkat+bTrojkat+cTrojkat;
        printf("\nObwod trojkata wynosi %.2lf\n\n",obwoTrojkata);
    }
}

void obliczeniaDlaKola(void){
    const double r;
    printf("Podaj dlugosc promienia kola: ");
    scanf("%lf",&r);
    sprawdzCzyNieujemnaWartosc(r);
    int wyborDzialania=coObliczyc();
    if (wyborDzialania==1){
        double poleKola=M_PI*r*r;
        printf("\nPole kola wynosi %.2lf\n\n",poleKola);
    }
    if (wyborDzialania==2){
        double obwodKola=2*M_PI*r;
        printf("\nObwod kola wynosi %.2lf\n\n",obwodKola);
    }
}

int coObliczyc(void){
    const int wyborDzialania;
    printf("\nWybierz, co chcesz obliczyc:\n\t1: pole\n\t2: obwod\n");
    printf("\nObliczam: ");
    scanf("%d",&wyborDzialania);
    if ((wyborDzialania!=1)&&(wyborDzialania!=2)){
        printf("Wpisano zla wartosc\n");
        coObliczyc();
    }
    return wyborDzialania;
}

int sprawdzCzyNieujemnaWartosc(double a){
    if (a<=0){
        return 1;
    }
    else{
        return 0;
    }
}

int sprawdzCzyTrojkatOTakichBokachIstnieje(double a, double b, double c){
    if ((a+b>c)&&(b+c>a)&&(a+c>b)){
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
    scanf("%d",&wyborFigury);
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
