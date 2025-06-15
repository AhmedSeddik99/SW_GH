#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1 [10];
    char str2 [10];

    int i;

    puts("Enter the string");
    gets(str2);

    for(i = 0; i < 10; i++)
    {
        str1[i] = str2[i];
    }

    puts(str1);



    return 0;
}
