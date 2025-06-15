#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"


int main()
{
    int i, j;
    int n, m;
    int r = 0;
    int c = 0;
    int elements = 0;
    int** marks;
    int col_len[rows];

    printf("Enter the number of row \n");
    scanf("%d", n);

//    printf("Enter the number of row \n");
//    scanf("%d", m);

    for(i = 0; i < rows; i++)
    {

        scanf("%d", &col_len[i]);
        elements += col_len[i];
    }




    for(i = 0; i < elements; i++)
    {
        printf("Enter the value of element (%d, %d)\n", r, c);
        scanf("%d", &arr[i]);
        c++;

        if(c == (col_len[r]))
        {
            c = 0;
            r++;
        }
    }

    c = 0;
    r = 0;

    for(i = 0; i < elements; i++)
    {
        printf("The value of element (%d, %d) = %d\n", r, c, arr[i]);
        c++;

        if(c == (col_len[r]))
        {
            c = 0;
            r++;
        }
    }

    return 0;
}
