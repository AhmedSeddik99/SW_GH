#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    printf("Enter a character\n");
    ch = getche();

    if(ch == -32)
    {
        printf("\nExtended Key & it's ASCII = %d\n", ch);
        ch = getche();
        printf("%d\n", ch);
    }
    else
    {
        printf("\nNormal Key & it's ASCII = %d\n", ch);
    }


    return 0;
}
