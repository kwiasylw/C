#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int pobieranieWybranejCzesciAktualnejDaty(char* symbolDlaWybranejCzesciDaty){
    time_t czas;
    struct tm* data;
    char wybranaCzescAktualnejDaty[20];
    time(&czas);
    data=localtime(&czas);
    strftime(wybranaCzescAktualnejDaty, 20, symbolDlaWybranejCzesciDaty, data);
    int wybranaCzescAktualnejDatyJakoInt=atoi(wybranaCzescAktualnejDaty);
    return wybranaCzescAktualnejDatyJakoInt;
}

int uzyskanieDniaTygodniaPierwszegoDniaMiesiaca(int aktualnyDzienMiesiaca, int aktualnyDzienTygodnia){
    for(int i=aktualnyDzienMiesiaca-1; i>=1; i--){
        aktualnyDzienTygodnia--;
        if(aktualnyDzienTygodnia==0){
            aktualnyDzienTygodnia+=7;
        }
    }
    int dzienPierwszegoDniaMiesiaca=aktualnyDzienTygodnia;
    return dzienPierwszegoDniaMiesiaca;
}

int przypisanieOdpowiedniejIlosciDniDlaDanegoMiesiaca(int dni, int miesiac){
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
    return dni;
}

void wypisywanieKalendarzaLamiacCo7Dni(int start, int dni){
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
}

int main(void){
    int aktualnyDzienMiesiaca=pobieranieWybranejCzesciAktualnejDaty("%d");
    int aktualnyDzienTygodnia=pobieranieWybranejCzesciAktualnejDaty("%w");
    int aktualnyMiesiac=pobieranieWybranejCzesciAktualnejDaty("%m");
    int start=uzyskanieDniaTygodniaPierwszegoDniaMiesiaca(aktualnyDzienMiesiaca, aktualnyDzienTygodnia);
    int dni=przypisanieOdpowiedniejIlosciDniDlaDanegoMiesiaca(dni, aktualnyMiesiac);
    printf("\t***Program wyswietla aktualny miesiac***\n");
    wypisywanieKalendarzaLamiacCo7Dni(start, dni);
    return 0;
}
