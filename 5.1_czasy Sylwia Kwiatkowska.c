#include <stdio.h>


int porownywanieCzasow(int czas1[], int czas2[]){
    int i,j,godzina1,godzina2,minuta1,minuta2,sekunda1,sekunda2;
    godzina1=czas1[0];
    godzina2=czas2[0];
    minuta1=czas1[1];
    minuta2=czas2[1];
    sekunda1=czas1[2];
    sekunda2=czas2[2];

    if ((godzina2<=23) && (godzina1<=23)
        && (minuta1<=59) && (minuta2<=59) && (sekunda1=59) && (sekunda2<=59)
        && (godzina1>=0) && (godzina2>=0) && (sekunda1>=0) && (sekunda2>=0) && (minuta1>=0) && (minuta2>=0)){

            for (i=0;i<3;i++){
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

    else{
        printf("\n\nZly zapis czasu!!\n");
        printf("ERROR ");
        return 404;

    }

}

int main(int argc, char *argv[]){

    printf("Program porownuje dwie godziny\n\n");
    printf("Legenda: \n\t-1: czas pierwszy jest wczesniej \n\t 0: czasy sa rowne \n\t 1:czas drugi jest wczesniej\n\n\n");
    int i;
    int tablica1[3];
    int tablica2[3];

    printf("\nPodaj pierwsza godzine w formacie GG-MM-SS: \n");

    for(i=0;i<3;i++){
        printf("\t%d wartosc: ",i+1);
        scanf("%d",&tablica1[i]);
        }

    printf("\n\nPodaj druga godzine w formacie GG-MM-SS: \n");
    for(i=0;i<3;i++){
        printf("\t%d wartosc: ",i+1);
        scanf("%d",&tablica2[i]);
        }

    printf("%d",porownywanieCzasow(tablica1,tablica2));
    printf("\n\n\n");
    return 0;
}
