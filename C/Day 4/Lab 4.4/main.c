#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

int main()
{
    char ch;
    char menu[3][8] = {"New", "Display", "Exit"};

    int i;
    int current = 0;
    int flag = 0;

    struct Employee e1;

    e1 = AddNewEmployee();
    DisplayEmployee(e1);


    do
    {
        textattr(0X07);
        clrscr();

        for(i = 0; i < 3; i++)
        {
            if(current == i)
                textattr(0X70);
            else
                textattr(0X07);

            gotoxy(15, 4*i+3);
            printf(menu[i]);
        }

            ch = getche();
            switch(ch)
            {
                case -32:
                case 0:
                case 224:

                    ch = getche();
                    switch(ch)
                    {
                        case 72:    current--;              // Up
                                    if(current < 0)
                                        current = 2;
                                    break;

                        case 80:    current++;              // Down
                                    if(current > 2)
                                        current = 0;
                                    break;

                        case 71:    current = 0;            // Home
                                    break;

                        case 79:    current = 2;            // End
                                    break;
                    }

                break;

                case 27:    flag = 1;                   // Esc
                            break;

                case 9:     break;

                case 13:    if (current == 0)
                            {
                                clrscr();
                                printf("New Page");
                                getche();
                            }
                            else if (current == 1)
                            {
                                clrscr();
                                printf("Display Page...");
                                getche();
                            }
                            else
                            {
                                flag = 1;
                            }

                            break;
            }
        }
        while(flag != 1);

    return 0;
}
