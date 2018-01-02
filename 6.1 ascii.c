#include <stdio.h>

int main()
{
    int i;
    puts("Program wypisuje znaki ASCII od 0 do 255");
    for(i=0; i<=255; i++)
    {
        printf("%c ma kod ASCII: %d\n", i, i);
    }

    return 0;
}
