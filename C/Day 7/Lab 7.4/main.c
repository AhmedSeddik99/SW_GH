#include <stdio.h>
#include <stdlib.h>
#include "E:\CodeBlocks\MinGW\include\MyLibrary.h"


int main()
{
    int i,j;
    int sum = 0;
    int avg = 0;

    int** marks = NULL;
    int no_std, no_sub;

    printf("Enter the number of the students\n");
    scanf("%d", &no_std);

    printf("Enter the number of the subjects\n");
    scanf("%d", &no_sub);

    marks = malloc(no_std * sizeof(int*));


    /// Inputting
    for(i = 0; i < no_std; i++)
    {
        marks[i] = malloc(no_sub * sizeof(int));

        sum = 0;
        printf("Enter the marks of the student no. (%d)\n", i+1);
        printf("_________________________________________________\n");
        for(j = 0; j < no_sub; j++)
        {
            printf("Enter the marks of the subject no. (%d)\n", j+1);
            scanf("%d", &marks[i][j]);
            //sum += marks[i][j];
        }
        //printf("Sum of marks for student no. (%d) = %d\n", i+1, sum);
        printf("-------------------------------------------------\n");
    }


    /// Sum of marks for students
    for(i = 0; i < no_std; i++)
    {
        sum = 0;
        for(j = 0; j < no_sub; j++)
        {
            sum += marks[i][j];
        }
        printf("Sum of marks for student no. (%d) = %d\n", i+1, sum);
        printf("_________________________________________________\n");
    }

    /// Avg of marks for students
    for(j = 0; j < no_sub; j++)
    {
        sum = 0;
        for(i = 0; i < no_std; i++)
        {
            sum += marks[i][j];
        }
        avg = sum / no_sub;
        printf("Average of marks for subject no. (%d) = %d\n", j+1, avg);
        printf("_________________________________________________\n");
    }


    free(marks);
    return 0;
}
