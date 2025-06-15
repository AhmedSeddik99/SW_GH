#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

#define rows 3

int main()
{
    int i, j;
    int r = 0;
    int c = 0;
    int elements = 0;
    int col_len[rows];

    for(i = 0; i < rows; i++)
    {
        printf("Enter the number of columns for row (%d)\n", i);
        scanf("%d", &col_len[i]);
        elements += col_len[i];
    }

    int arr[elements];


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
