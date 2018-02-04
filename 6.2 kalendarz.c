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
        if(aktualnyDzienTygodnia==0){
            aktualnyDzienTygodnia+=7;
        }
        aktualnyDzienTygodnia--;
    }
    int dzienPierwszegoDniaMiesiaca=aktualnyDzienTygodnia;
    return dzienPierwszegoDniaMiesiaca;
}

int przypisanieOdpowiedniejIlosciDniDlaDanegoMiesiaca(int dni, int miesiac, int rok){
    if(miesiac==1 || miesiac==3 || miesiac==5 || miesiac==7 || miesiac==8 || miesiac==10 || miesiac==12){
        dni=31;
    }
    else if(miesiac==4 || miesiac==6 || miesiac==9 || miesiac==11){
        dni=30;
    }
    else if(miesiac==2){
        if (rok%4==0){
            dni=29;
        }
        else{
            dni=28;
        }
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
    int aktualnyRok=pobieranieWybranejCzesciAktualnejDaty("%Y");
    int start=uzyskanieDniaTygodniaPierwszegoDniaMiesiaca(aktualnyDzienMiesiaca, aktualnyDzienTygodnia);
    int dni=przypisanieOdpowiedniejIlosciDniDlaDanegoMiesiaca(dni, aktualnyMiesiac, aktualnyRok);
    printf("\t***Program wyswietla aktualny miesiac***\n");
    wypisywanieKalendarzaLamiacCo7Dni(start, dni);
    printf("\n\nDzisiejsza data: %d.%d.%d\n", aktualnyDzienMiesiaca, aktualnyMiesiac, aktualnyRok);
    return 0;
}
