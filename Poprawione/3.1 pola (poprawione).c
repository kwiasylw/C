#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sprawdzCzyNieujemnaWartosc(int a){
    if (a<=0){
        printf("Bledna wartosc");
        exit(1);
    }
    else{
        printf("");
    }
}

int coObliczyc(void){
    int poleObw;
    printf("\nWybierz, co chcesz obliczyc:\n\t1: pole\n\t2: obwod\n");
    printf("\nObliczam: ");
    scanf("%d",&poleObw);
    if ((poleObw!=1)&&(poleObw!=2)){
        printf("Wpisano zla wartosc\n");
        exit(1);
    }
    return poleObw;
}

void sprawdzCzyTrojkatOTakichBokachIstnieje(int a,int b,int c){
    if ((a+b>c)&&(b+c>a)&&(a+c>b)){
        printf("");
    }
    else{
        printf("Trojkat o takich bokach nie istnieje.");
        exit(1);
    }
}

int main(void){
    int wybor;
    double aKwadrat,aProstokat,bProstokat,aTrojkat,bTrojkat,cTrojkat,wysokoscTrojkata,r;
    printf("\nProgram oblicza pola lub obwody figur geometrycznych: \n");
    printf("\t1: kwadrat\n\t2: prostokat\n\t3: trojkat\n\t4: kolo \n");
    printf("\nWpisz swoj wybor: ");
    scanf("%d",&wybor);

    switch (wybor){
    case 1:
        printf("Wpisz dlugosc boku kwadratu: ");
        scanf("%lf",&aKwadrat);
        sprawdzCzyNieujemnaWartosc(aKwadrat);
        int poleObw1=coObliczyc();
        if (poleObw1==1){
            double poleKwadratu=aKwadrat*aKwadrat;
            printf("\nPole kwadratu wynosi %.2lf\n\n",poleKwadratu);
        }
        if (poleObw1==2){
            double obwodKwadratu=4*aKwadrat;
            printf("\nObwod kwadratu wynosi %.2lf\n\n",obwodKwadratu);
        }
        break;
    case 2:
        printf("Wpisz dlugosci pierwszego i drugiego boku prostokata: ");
        scanf("%lf %lf",&aProstokat,&bProstokat);
        sprawdzCzyNieujemnaWartosc(aProstokat);
        sprawdzCzyNieujemnaWartosc(bProstokat);
        int poleObw2=coObliczyc();
        if (poleObw2==1){
            double poleProstokata=aProstokat*bProstokat;
            printf("\nPole prostokata wynosi %.2lf\n\n",poleProstokata);
        }
        if (poleObw2==2){
            double obwodProstokata=2*(aProstokat+bProstokat);
            printf("\nObwod prostokata = %.2lf\n\n",obwodProstokata);
        }
        break;
    case 3:
        printf("Podaj dlugosci trzech bokow trojkata (rozdzielone spacja):");
        scanf("%lf %lf %lf",&aTrojkat,&bTrojkat,&cTrojkat);
        printf("Podaj dlugosc wysokosci trojkata: ");
        scanf("%lf",&wysokoscTrojkata);
        printf("\n");
        sprawdzCzyTrojkatOTakichBokachIstnieje(aTrojkat,bTrojkat,cTrojkat);
        sprawdzCzyNieujemnaWartosc(aTrojkat);
        sprawdzCzyNieujemnaWartosc(bTrojkat);
        sprawdzCzyNieujemnaWartosc(cTrojkat);
        sprawdzCzyNieujemnaWartosc(wysokoscTrojkata);
        int poleObw3=coObliczyc();
        if (poleObw3==1){
            double poleTrojkata=aTrojkat*wysokoscTrojkata/2;
            printf("\nPole trojkata wynosi %.2lf\n\n",poleTrojkata);
        }
        if (poleObw3==2){
            double obwoTrojkata=aTrojkat+bTrojkat+cTrojkat;
            printf("\nObwod trojkata wynosi %.2lf\n\n",obwoTrojkata);
        }
        break;
    case 4:
        printf("Podaj dlugosc promienia kola: ");
        scanf("%lf",&r);
        sprawdzCzyNieujemnaWartosc(r);
        int poleObw4=coObliczyc();
        if (poleObw4==1){
            double poleKola=M_PI*r*r;
            printf("\nPole kola wynosi %.2lf\n\n",poleKola);
        }
        if (poleObw4==2){
            double obwodKola=2*M_PI*r;
            printf("\nObwod kola wynosi %.2lf\n\n",obwodKola);
        }
        break;
    }
    return 0;
}
