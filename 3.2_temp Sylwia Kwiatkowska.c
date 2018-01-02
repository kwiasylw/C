#include <stdio.h>

int main()
{
    float tempF,tempC;
    int wybor;
    printf("Program przelicza temperature w skalach stopnie Celsjusza <-> stopnie Fahrenheita\n\n");
    printf("\t1: stopnie Fahrenheita -> stopnie Celsjusza\n");
    printf("\t2: stopnie Celsiusza -> Fahrenheita\n");
    printf("\nWpisz wybor (1 lub 2): ");
    scanf("%d",&wybor);

    if(wybor==1){
        printf("Wpisz temperature w stopniach Fahrenheita: ");
        scanf("%f",&tempF);
        tempC= (tempF - 32) / 1.8;
        printf("Temperatura w stopniach Celsjusza wynosi: %.2f\n",tempC);
    }

    else if(wybor==2){
        printf("Wpisz temperature w stopniach Celsjusza: ");
        scanf("%f",&tempC);
        tempF=(tempC*1.8)+32;
        printf("Temperatura w stopniach Fahrenheita wynosi: %.2f\n",tempF);
    }

    else{
        printf("\nZly wybor");
    }

return 0;
}
