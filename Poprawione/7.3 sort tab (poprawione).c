#include <stdio.h>
#include <time.h>


int main(void) {
    int i,tab[10];
    srand(time(NULL));
    for(i=0;i<10;i++){
        tab[i]=rand()%30;
    }
    int j,*wsk[10];
    puts("***POCZATKOWO***");
    puts("L.P.\ttab A\ttab B");
    puts("---------------------");
    for (j=0;j<10; j++){
        wsk[j]=&tab[j];
    }
    for (j=0;j<10;j++){
        printf("%d\t%d\t%d\n",j,tab[j],*wsk[j]);
    }

    int *tmp;
    int k;
    //sortowanie
    for (k=0;k<10;k++){
        for (j=0;j<9;j++){
            if (*wsk[j]>*wsk[j+1]){
                tmp=wsk[j+1];
                wsk[j+1]=wsk[j];
                wsk[j]=tmp;
            }
        }
    }

    puts("\n");
    puts("***REZULTAT KONCOWY***");
    puts("L.P.\ttab A\ttab B");
    puts("---------------------");
    for (j=0;j<10;j++){
        printf("%d\t%d\t%d\n",j,tab[j],*wsk[j]);
   }
    return 0;
}
