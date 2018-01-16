#include <stdio.h>

void fahrenheityNaCelsjusze(void){
    float tempWFahrenheitach, tempWCelsjuszach;
    printf("Wpisz temperature w stopniach Fahrenheita: ");
    scanf("%f", &tempWFahrenheitach);
    tempWCelsjuszach=(tempWFahrenheitach-32)/1.8;
    printf("Temperatura w stopniach Celsjusza wynosi: %.2f\n", tempWCelsjuszach);
}

void celsjuszeNaFahrenheity(void){
    float tempWCelsjuszach, tempWFahrenheitach;
    printf("Wpisz temperature w stopniach Celsjusza: ");
    scanf("%f", &tempWCelsjuszach);
    tempWFahrenheitach=(tempWCelsjuszach*1.8)+32;
    printf("Temperatura w stopniach Fahrenheita wynosi: %.2f\n", tempWFahrenheitach);
}

int main(){
    int wybor;
    printf("Program przelicza temperature w skalach stopnie Celsjusza <-> stopnie Fahrenheita\n\n");
    printf("\t1: stopnie Fahrenheita -> stopnie Celsjusza\n");
    printf("\t2: stopnie Celsiusza -> Fahrenheita\n");
    printf("\nWpisz wybor (1 lub 2): ");
    scanf("%d", &wybor);
    if(wybor==1){
        fahrenheityNaCelsjusze();
    }
    else if(wybor==2){
        celsjuszeNaFahrenheity();
    }
    else{
        printf("\nZly wybor");
    }
    return 0;
}
