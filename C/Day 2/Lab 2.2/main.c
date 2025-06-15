#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

int main()
{
    char ch;

    do {
        printf("Simple Menu:\nA- Good Morning\nB- Good Evening\nC- Exit\n");
        printf("\nEnter your choice\n");
        //scanf("%c", &ch);                 // wrong as "Enter" is considered as a character too
        ch = getch();
        switch(ch)
        {
            case 'A':   clrscr();
                        printf("Good Morning\n");
                        getch();
                        clrscr();
            break;

            case 'B':   clrscr();
                        printf("Good Evening\n");
                        getch();
                        clrscr();
            break;
        }
    }
    while(ch != 'C');

    printf("Exit");
    return 0;
}
