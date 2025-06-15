#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"

#define students 3
#define subjects 4

int main()
{
    int arr[students][subjects];
    int i,j;
    int sum = 0;

    for(i = 0; i < students; i++)
    {
        getch();
        clrscr();
        sum = 0;
        printf("Enter the values of the student number %d\n", i+1);
        printf("________________________________________________\n");
        for(j = 0; j < subjects; j++)
        {
            printf("Enter the values of the subject number %d\n", j+1);
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
        printf("Sum of marks for student no.(%d) = %d\n", i+1, sum);
    }

    return 0;
}
