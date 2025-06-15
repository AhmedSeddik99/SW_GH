#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    char str [20];
    int i, len;
    int cnt = 0;

    puts("Enter string");
    gets(str);

    puts("Enter the character");
    ch = getche();

    len = strlen(str);
    //printf("%d", len);


    for(i = 0; i < len; i++)
    {
        //printf("%c\n", str[i]);
        if(str[i] == ch)
            cnt++;
    }

    printf("\n The frequency of %c is %d\n", ch, cnt);


    return 0;
}
