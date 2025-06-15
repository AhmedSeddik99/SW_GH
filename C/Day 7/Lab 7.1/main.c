#include <stdio.h>
#include <stdlib.h>


int PowerCalc(int Base, int Power);

int main()
{
    int Base, Power;

    printf("Enter the Base & the Power\n");
    scanf("%d", &Base);
    scanf("%d", &Power);

    printf("The Result = %d\n", PowerCalc(Base,Power));
    return 0;
}



int PowerCalc(int Base, int Power)
{
    int mult = Base;


    if(Power == 1)
    {
        return mult;
    }
    else
    {
        mult *= PowerCalc(mult, Power-1);
    }
}


