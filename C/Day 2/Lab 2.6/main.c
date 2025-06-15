#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    printf("Enter a character\n");
    scanf("%c", &ch);

    if(ch >= 'A' && ch <= 'z')
    {
        printf("The character is an alphabet\n");
    }
    else
    {
        printf("The character isn't an alphabet\n");
    }
    return 0;
}
