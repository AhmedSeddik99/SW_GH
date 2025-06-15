#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

#define rows 3
#define cols 4

int main()
{
    int i,j;
    float arr[rows][cols];
    float sum = 0;
    float avg = 0;


    for(i = 0; i < rows; i++)
    {
        printf("________________________________________________\n");
        printf("Enter the values of the row number %d\n", i+1);
        printf("________________________________________________\n");

        for(j = 0; j < cols; j++)
        {
            printf("Enter the values of the col number %d\n", j+1);
            scanf("%f", &arr[i][j]);
        }
    }

    for(j = 0; j < cols; j++)
    {
        sum = 0;
        avg = 0;
        for(i = 0; i < rows; i++)
        {
            sum += arr[i][j];
        }
        //printf("Sum of column no.(%d) = %f\n", j+1, sum);
        avg = sum / rows;
        printf("Average of column no.(%d) = %f\n", j+1, avg);

    }


    return 0;
}
