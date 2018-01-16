#include <stdio.h>

int main(){
    printf("***Program wyswietla dany miesiac***\n");
    int miesiac, dni, start;
    printf("Podaj numer miesiaca (1-12): ");
    scanf("%d", &miesiac);
    if(miesiac==1 || miesiac==3 || miesiac==5 || miesiac==7 || miesiac==8 || miesiac==10 || miesiac==12){
        dni=31;
    }
    else if(miesiac==4 || miesiac==6 || miesiac==9 || miesiac==11){
        dni=30;
    }
   else if(miesiac==2){
        int przestepny;
        printf("Czy rok jest przestepny? Wpisz 1(tak) lub 2(nie): ");
        scanf("%d", &przestepny);
        switch(przestepny){
        case 1:
            dni=29;
            break;
        case 2:
            dni=28;
            break;
       default:
            printf("ERROR. Wpisz T lub N.");
            break;
        }
    }
    else{
        printf("ERROR. Podaj liczbe od 1 do 12.");
            scanf("%d", &miesiac);
    }

    puts("\nKtorego dnia rozpoczyna sie miesiac?");
    puts("\t*Poniedzialek \t- wybierz 1");
    puts("\t*Wtorek \t- wybierz 2");
    puts("\t*Sroda\t\t- wybierz 3");
    puts("\t*Czwartek\t- wybierz 4");
    puts("\t*Piatek\t\t- wybierz 5");
    puts("\t*Sobota\t\t- wybierz 6");
    puts("\t*Niedziela\t- wybierz 7");
    printf("\nWpisz liczbe (1-7): ");
    scanf("%d", &start);

    puts("\nPON\tWT\tSR\tCZW\tPT\tSOB\tNDZ\n");
    for(int i=1; i<=dni+start-1; i++){
        if(i<start){
            printf(" \t");
        }
        else{
            printf("%d\t", i-start+1);
        }
        if((i%7)==0){ //przejscie do nowej linii co 7 dni
            printf("\n");
        }
    }
    return 0;
}
