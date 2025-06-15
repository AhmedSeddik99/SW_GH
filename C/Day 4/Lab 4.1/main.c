#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    char str[10];

    int i;


    for(i = 0; i < 10; i++)
    {
        printf("\nEnter a character\n");
        ch = getche();
        if(ch == 13)
        {
            break;
        }
        else
        {
            str[i] = ch;
        }
    }

    printf(str);

    return 0;
}
