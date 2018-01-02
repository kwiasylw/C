#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Program liczy pierwiastki rownania kwadratowego.\n\n");
    float delta,pierwiastek,x1,x2;
    int a,b,c;
    printf("Podaj wartosci wspolczynnikow: ax^2+bx+c \n");
    printf("\ta=");
    scanf("%d",&a);
    printf("\tb=");
    scanf("%d",&b);
    printf("\tc=");
    scanf("%d",&c);

    if (a==0){
        printf("Wspolczynnik a musi byc rozny od zera!!\n");
    }

    else{
        delta=b*b-4.*a*c;
        printf("\nDelta wynosi: %.1f \n", delta);

        if (delta<0){
            printf("\nBrak rozwiazan\n");
        }

        if(delta==0){
            x1=-b/2*a;
            printf("Pierwiastek rownania: %.1f\n",x1);
        }

        if (delta>0){
            pierwiastek=sqrt(delta);
            x1=(-b-pierwiastek)/2*a;
            x2=(-b+pierwiastek)/2*a;
            printf("\nPierwiastki rownania to %.1f, %.1f \n",x1,x2);
        }
    }

return 0;
}
