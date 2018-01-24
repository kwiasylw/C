#include <stdio.h>
#include <math.h>


float liczenieDelty(int a, int b, int c){
    float delta=b*b-4.*a*c;
    float pierwiastek, x1, x2;
    printf("\nDelta wynosi: %.1f \n", delta);
    if(delta<0){
        printf("\nBrak rozwiazan\n");
    }
    if(delta==0){
        x1=-b/2*a;
        printf("Pierwiastek rownania: %.1f\n", x1);
    }
    if(delta>0){
        pierwiastek=sqrt(delta);
        x1=(-b-pierwiastek)/2*a;
        x2=(-b+pierwiastek)/2*a;
        printf("\nPierwiastki rownania to %.1f, %.1f \n", x1, x2);
    }
}

int main(void){
    printf("Program liczy pierwiastki rownania kwadratowego.\n\n");
    int a, b, c;
    printf("Podaj wartosci wspolczynnikow: ax^2+bx+c (oddzielone spacjami)\n");
    printf("Wspolczynniki a b c : ");
    scanf("%d %d %d", &a, &b, &c);
    if(a==0){
        printf("Wspolczynnik a musi byc rozny od zera!!\n");
    }
    else{
        liczenieDelty(a, b, c);
    }
    return 0;
}
