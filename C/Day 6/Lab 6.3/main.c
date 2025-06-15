#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"


int main()
{
    char ch;
    char sentence[20] = {0};

    int i;
    int cnt = 0;
    int current = 0;
    int flag = 0;


    for(i = 0; i < 20; i++)
        {
            textattr(0X40);
            gotoxy(i+3, 15);
            printf(" ");
        }

        gotoxy(3, 15);

    do
    {
        ch = getch();
            switch(ch)
            {
                case -32:
                case 0:
                case 224:

                    ch = getch();
                    switch(ch)
                    {
                        case 75:    current--;                  // Left
                                    if(current < 0)
                                        current = 19;
                                    gotoxy(current+3, 15);
                                    break;

                        case 77:    current++;                  // Right
                                    if(current > 20)
                                        current = 0;
                                    gotoxy(current+3, 15);
                                    break;

                        case 71:    current = 0;                // Home
                                    gotoxy(current+3, 15);
                                    break;

                        case 79:    current = 19;               // End
                                    gotoxy(current+3, 15);
                                    break;

                    }

                break;

                case 13:
                case 27:
                            flag = 1;                           // Esc
                            break;


                default:    gotoxy(current+3, 15);
                            current ++;
                            if(current > 19)
                            {
                                current = 0;
                            }
                            printf("%c", ch);
                            sentence[cnt] = ch;
                            cnt ++;
            }
    }
    while(flag != 1);

    textattr(0X07);
    clrscr();

    printf("Sentence: %s", sentence);

    return 0;
}
