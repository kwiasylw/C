#include <stdio.h>
#include <math.h>

int main()
{
    int wybor;
    printf("\nProgram oblicza pola lub obwody figur geometrycznych: \n");
    printf("\t1: kwadrat\n\t2: prostokat\n\t3: trojkat\n\t4: kolo \n");
    printf("\nWpisz swoj wybor: ");
    scanf("%d",&wybor);

    switch(wybor){
        case 1:
            ;
            double aKw;
            printf("Wpisz dlugosc boku kwadratu: ");
            scanf("%lf",&aKw);

            if (aKw<=0){
                printf("Bledna wartosc");
            }

            else {
            int poleObw1;
            printf("\nWybierz, co chcesz obliczyc:\n\t1: pole\n\t2: obwod\n");
            printf("\nObliczam: ");
            scanf("%d",&poleObw1);

            if(poleObw1==1){
                double poleKw;
                poleKw=(aKw*aKw);
                printf("\nPole kwadratu wynosi %.2lf\n\n", poleKw);
                return 0;
            }
            if(poleObw1==2){
                double obwodKw;
                obwodKw=4*aKw;
                printf("\nObwod kwadratu wynosi %.2lf\n\n", obwodKw);
                return 0;
            }
            }
            break;

        case 2:
            ;
            double aPr;
            double bPr;
            printf("Wpisz dlugosc pierwszego boku prostokata: ");
            scanf("%lf",&aPr);
            printf("Wpisz dlugosc drugiego boku prostokata: ");
            scanf("%lf",&bPr);

            if ((aPr<=0) && (bPr<=0)){
                printf("Bledna wartosc");
            }

            else{
            int poleObw2;
            printf("\nWybierz, co chcesz obliczyc:\n\t1: pole\n\t2: obwod\n");
            printf("\nObliczam: ");
            scanf("%d",&poleObw2);

            if(poleObw2==1){
                double polePr=(aPr*bPr);
                printf("\nPole prostokata wynosi %.2lf\n\n", polePr);
                return 0;
            }

            if(poleObw2==2){
                double obwodPr=2*(aPr+bPr);
                printf("\nObwod prostokata = %.2lf\n\n", obwodPr);
                return 0;
            }

            }
            break;

        case 3:
            ;
            double aTr,hTr,bTr,cTr;
            printf("Podaj dlugosc pierwszego boku trojkata:\t");
            scanf("%lf",&aTr);
            printf("Podaj dlugosc drugiego boku trojkata:\t");
            scanf("%lf",&bTr);
            printf("Podaj dlugosc trzeciego boku trojkata:\t");
            scanf("%lf",&cTr);
            printf("Podaj dlugosc wysokosci trojkata:\t");
            scanf("%lf",&hTr);
            printf("\n");

            if ((aTr+bTr>cTr)&&(bTr+cTr>aTr)&&(aTr+cTr>bTr)){

                if ((aTr<=0)&&(bTr<=0)&&(cTr<=0)&&(hTr<=0)) {
                    printf("Bledna wartosc");
                }

                else{
                int poleObw3;
                printf("\nWybierz, co chcesz obliczyc:\n\t1: pole\n\t2: obwod\n");
                printf("\nObliczam: ");
                scanf("%d",&poleObw3);

                if(poleObw3==1){
                    double poleTr;
                    poleTr = (aTr*hTr/2);
                    printf("\nPole trojkata wynosi %.2lf\n\n",poleTr);
                    return 0;
                }

                if(poleObw3=2){
                    double obwodTr = (aTr+bTr+cTr);
                    printf("\nObwod trojkata wynosi %.2lf\n\n", obwodTr);
                    return 0;
                }
                }
            }
            else{
                printf("Trojkat o takich bokach nie istnieje.");

            }
            break;

        case 4:
            ;
            double r;
            printf("Podaj dlugosc promienia kola: ");
            scanf("%lf",&r);

            if (r<=0){
                printf("Bledna wartosc");
            }

            else{
            int poleObw4;
            printf("\nWybierz, co chcesz obliczyc:\n\t1: pole\n\t2: obwod\n");
            printf("\nObliczam: ");
            scanf("%d",&poleObw4);

            if(poleObw4==1){
                double poleKola;
                poleKola = (M_PI*(r*r));
                printf("\nPole kola wynosi %.2lf\n\n",poleKola);
                return 0;
            }

            if(poleObw4=2){
                double obwodKola;
                obwodKola = (2*M_PI*r);
                printf("\nObwod kola wynosi %.2lf\n\n",obwodKola);
                return 0;

            }
            }
            ;
            break;
        }
    }
