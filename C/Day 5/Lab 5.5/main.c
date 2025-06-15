#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

#define no_employees 5


struct Employee
{
    int ID;
    char name[20];
    float salary;
    float bonus;
    float deduction;
};


struct Employee AddNewEmployee()
{
    struct Employee e1;

    printf("Enter an employee ID\n");
    scanf("%d", &e1.ID);

    printf("Enter an employee name\n");
    _flushall();
    scanf("%s", &e1.name);
    //gets(e1.name);

    printf("Enter an employee salary\n");
    scanf("%f", &e1.salary);

    printf("Enter an employee bonus\n");
    scanf("%f", &e1.bonus);

    printf("Enter an employee deduction\n");
    scanf("%f", &e1.deduction);

    return e1;
}



void DisplayEmployee(struct Employee e1)
{
    float net_salary = 0;
    float net_bonus = 0;
    float net_deduction = 0;

    net_bonus = (e1.bonus/100)*e1.salary;
    net_deduction = (e1.deduction/100)*e1.salary;

    net_salary = e1.salary + net_bonus - net_deduction;

    printf("Employee: (%d, %s) his net salary = %f\n", e1.ID, e1.name, net_salary);
}



int main()
{
    char ch;
    char menu[6][12] = {"New", "Display", "Display All", "Delete", "Delete All", "Exit"};

    int i;
    int current = 0;
    int flag = 0;
    int idx = 0;


    struct Employee EmpArr[no_employees];

    do
    {
        textattr(0X07);
        clrscr();

        for(i = 0; i < 6; i++)
        {
            if(current == i)
                textattr(0X70);
            else
                textattr(0X07);

            gotoxy(15, 4*i+3);
            printf(menu[i]);
        }

            ch = getche();
            switch(ch)
            {
                case -32:
                case 0:
                case 224:

                    ch = getche();
                    switch(ch)
                    {
                        case 72:    current--;              // Up
                                    if(current < 0)
                                        current = 5;
                                    break;

                        case 80:    current++;              // Down
                                    if(current > 5)
                                        current = 0;
                                    break;

                        case 71:    current = 0;            // Home
                                    break;

                        case 79:    current = 5;            // End
                                    break;
                    }

                break;

                case 27:    flag = 1;                   // Esc
                            break;

                case 9:     break;

                case 13:    switch(current)
                            {
                                case 0: clrscr();
                                        printf("\t\t\t *** New Employee ***\n");
                                        if(idx < no_employees)        // idx = no_employees then no new employees can be added to prevent overwritten
                                        {
                                            EmpArr[idx] = AddNewEmployee();
                                            idx ++;
                                        }
                                        getche();
                                        break;


                                case 1: clrscr();
                                        if(idx > 0)         // if idx = 0 then no employees to be displayed
                                        {
                                            printf("\t\t\t *** Display Employee no.(%d) ***\n", (idx-1));
                                            DisplayEmployee(EmpArr[idx-1]);
                                        }
                                        else
                                            printf("\t\t\t *** No Employees to be displayed *** \n");
                                        getche();
                                        break;


                                case 2: clrscr();
                                        if(idx > 0)         // if idx = 0 then No New Employees have been added
                                        {
                                            printf("\t\t\t *** Display All ***\n");
                                            for(i = 0; i < idx; i++)
                                            {
                                                DisplayEmployee(EmpArr[i]);
                                            }
                                        }
                                        else
                                            printf("\t\t\t *** No Employees to be displayed *** \n");
                                        getche();
                                        break;


                                case 3: clrscr();
                                        if(idx > 0)
                                        {
                                            printf("\t\t\t *** Delete Employee no.(%d) ***\n", idx);
                                            idx --;
                                        }
                                        else
                                            printf("\t\t\t *** No Employees to be deleted *** \n");
                                        getche();
                                        break;

                                case 4: clrscr();
                                        printf("\t\t\t *** All Employees have been deleted ***\n");
                                        idx = 0;
                                        getche();
                                        break;

                                case 5: flag = 1;
                                        break;

                            }
            }
        }
        while(flag != 1);

    return 0;
}
