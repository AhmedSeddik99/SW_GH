#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

#define rows 2
#define cols 3

int main()
{
    int i,j;
    int arr1[rows][cols] = {1, 2, 3, 4, 5, 6};
    int arr2[rows][cols] = {1, 2, 3, 4, 5, 6};
    int arr3[rows][cols];


    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
            printf("Array 1 (%d)(%d) + Array 2 (%d)(%d) = %d\n", i, j, i, j, arr3[i][j]);
        }
    }



    return 0;
}
