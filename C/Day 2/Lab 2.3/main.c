#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

int main()
{
    int i = 1;
    int x, size;
    int row = 1;
    int col;

    printf("Enter the size of the magic box\n");
    scanf("%d", &size);
    col = (size/2) + 1;
    printf("%d", col);
    clrscr();

    for(i = 1; i <= pow(size, 2); i++)
    {
        gotoxy(3*col, 3*row);
        printf("%d", i);
        for(x = 0; x < pow(10, 9); x++){};
        if((i % size) == 0)                     // number divisible by size
        {
            row ++;
            if(row > size)
            {
                row = 1;
            }
        }
        else
        {
            row --;
            col --;
            if(row == 0 && col == 0)        // row or col wrap up
            {
                row = size;
                col = size;
            }
            else if(row == 0)
            {
                row = size;
            }
            else if(col == 0)
            {
                col = size;
            }
        }
    }
    getch();
    return 0;
}
