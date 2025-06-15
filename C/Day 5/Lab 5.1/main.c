#include <stdio.h>
#include <stdlib.h>

int maxValue(int x, int y, int z);


int main()
{
    int x, y, z;
    int max;

    printf("Enter three values\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    max = maxValue(x, y, z);

    printf("Max Value among (%d, %d & %d) = %d", x, y, z, max);


    return 0;
}


int maxValue(int x, int y, int z)
{
    int max = x;


    /// max
    if(x > y)
    {
        if(x > z)
        {
            max = x;
        }
        else                /// z > x
        {
            max = z;
        }
    }
    else                    /// y > x
    {
        if(y > z)
        {
            max = y;
        }
        else                /// z > y
        {
            max = z;
        }
    }

    return max;
}



