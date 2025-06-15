#include <stdio.h>
#include <stdlib.h>

#define no_employees 5


typedef struct
{
    int ID;
    char name[20];
    float salary;
    float bonus;
    float deduction;
} emp;



int main()
{
    float net_salary = 0;
    float net_bonus = 0;
    float net_deduction = 0;

    int i;

    emp emp_structArr[no_employees];

    for(i = 0; i < no_employees; i++)
    {
        printf("Enter an employee ID\n");
        scanf("%d", &emp_structArr[i].ID);

        printf("Enter an employee name\n");
        scanf("%s", &emp_structArr[i].name);

        printf("Enter an employee salary\n");
        scanf("%f", &emp_structArr[i].salary);

        printf("Enter an employee bonus\n");
        scanf("%f", &emp_structArr[i].bonus);

        printf("Enter an employee deduction\n");
        scanf("%f", &emp_structArr[i].deduction);
    }


    for(i = 0; i< no_employees; i++)
    {
        net_bonus = (emp_structArr[i].bonus/100)*emp_structArr[i].salary;
        net_deduction = (emp_structArr[i].deduction/100)*emp_structArr[i].salary;
        net_salary = emp_structArr[i].salary + net_bonus - net_deduction;

        printf("Employee: (%d, %s) his net salary = %f\n", emp_structArr[i].ID, emp_structArr[i].name, net_salary);
    }


    return 0;
}
