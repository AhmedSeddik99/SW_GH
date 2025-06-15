#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cnt = 0;
    int no_alphabets = 0;
    int no_words = 0;
    char ch;

    printf("Enter the sentence\n");

    while(ch != 13)
    {
        ch = getch();
        printf("%c", ch);
        if(ch == ' ' || ch == 13)
        {
            no_words ++;
        }
        else
        {
            no_alphabets ++;
        }
    }
    printf("\nNumber of alphabets = %d", no_alphabets);
    printf("\nNumber of words = %d", no_words);


    return 0;
}
