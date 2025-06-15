#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int j = 0;
    int len = 0;
    char str1[] = {"Ahmed 123@$ Mohamed *&"};
    char str2[30];

    puts(str1);

    while(str1[i] != '\0')
    {
        if((str1[i] >= 'A' && str1[i] <= 'z'))
        {
            str2[j] = str1[i];
            j++;
        }
        i ++;
    }

    puts(str2);

    return 0;
}
