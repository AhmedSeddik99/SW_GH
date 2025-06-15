#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;

    printf("Enter Three Numbers\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    if(x > y)
    {
        if(x > z)
        {
            printf("x is the largest number");
        }
        else
        {
            printf("z is the largest number");
        }
    }
    else
    {
        if(y > z)
        {
            printf("y is the largest number");
        }
        else
        {
            printf("z is the largest number");
        }
    }

    return 0;
}
