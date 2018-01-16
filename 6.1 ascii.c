#include <stdio.h>

#define ZAKRESMAX 255

int main(void){
    puts("Program wypisuje znaki ASCII od 0 do 255");
    for(int i=0; i<=ZAKRESMAX; i++){
        printf("%c ma kod ASCII: %d\n", i, i);
    }
    return 0;
}
