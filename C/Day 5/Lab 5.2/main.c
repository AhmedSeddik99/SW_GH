#include <stdio.h>
#include <stdlib.h>


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

    emp emp_struct;

    printf("Enter an employee ID\n");
    scanf("%d", &emp_struct.ID);

    printf("Enter an employee name\n");
    scanf("%s", &emp_struct.name);

    printf("Enter an employee salary\n");
    scanf("%f", &emp_struct.salary);

    printf("Enter an employee bonus\n");
    scanf("%f", &emp_struct.bonus);

    printf("Enter an employee deduction\n");
    scanf("%f", &emp_struct.deduction);


    net_bonus = (emp_struct.bonus/100)*emp_struct.salary;
    net_deduction = (emp_struct.deduction/100)*emp_struct.salary;

    net_salary = emp_struct.salary + net_bonus - net_deduction;

    printf("Employee: (%d, %s) his net salary = %f", emp_struct.ID, emp_struct.name, net_salary);

    return 0;
}
