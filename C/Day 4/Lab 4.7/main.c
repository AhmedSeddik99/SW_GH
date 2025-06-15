#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int len = 0;
    char str[] = {"Ahmed Mohamed"};

    while(str[i] != '\0')
    {
        i ++;
        len ++;
    }

    printf("The Length of the string = %d\n", len);


    return 0;
}
