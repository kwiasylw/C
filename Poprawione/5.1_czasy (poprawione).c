#include <stdio.h>
#include <stdlib.h> //exit

void podawanieDanych(int n, int czas[n]){
    int i;
    for(i=0;i<n;i++){
        printf("\t%d wartosc: ",i+1);
        scanf("%d",&czas[i]);
    }
}

void sprawdzPoprawnoscDanych(int godz, int min, int sek){
    if ((godz>=0) && (godz<=23) && (min>=0) && (min<=59) && (sek>=0) && (sek<=59)){
        printf("Wprowadzono poprawne dane.");
    }
    else{
        printf("\n\nZly zapis czasu!!\n");
        printf("ERROR ");
        exit(1);
    }
}

int porownywanieCzasow(int n,int czas1[n], int czas2[n]){
    int i,j,godzina1,godzina2,minuta1,minuta2,sekunda1,sekunda2;
    godzina1=czas1[0];
    godzina2=czas2[0];
    minuta1=czas1[1];
    minuta2=czas2[1];
    sekunda1=czas1[2];
    sekunda2=czas2[2];
    sprawdzPoprawnoscDanych(godzina1,minuta1,sekunda1);
    for (i=0;i<n;i++){
        if (czas1[i]>czas2[i]){
            j=1;
            break;
        }
        if (czas1[i]<czas2[i]){
            j=-1;
            break;
        }
        else{
            j=0;
        }
    }
    printf("\n\nWYNIK: ");
    return j;
}

int main(int argc, char *argv[]){
    printf("Program porownuje dwie godziny\n\n");
    printf("Legenda: \n\t-1: czas pierwszy jest wczesniej \n\t 0: czasy sa rowne \n\t 1:czas drugi jest wczesniej\n\n\n");
    int czas1[3],czas2[3];
    printf("\nPodaj pierwsza godzine w formacie GG-MM-SS: \n");
    podawanieDanych(3,czas1);
    printf("\n\nPodaj druga godzine w formacie GG-MM-SS: \n");
    podawanieDanych(3,czas2);
    printf("%d",porownywanieCzasow(3,czas1,czas2));
    printf("\n\n\n");
    return 0;
}
