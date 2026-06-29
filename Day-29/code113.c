//Program to create menu-driven calculator
#include <stdio.h>
void add()
{
    float a,b;
    printf("\nEnter two numbers:");
    scanf("%f %f",&a,&b);
    printf("Result=%.2f\n",a+b);
}

void subtract()
{
    float a,b;
    printf("\nEnter two numbers:");
    scanf("%f %f",&a,&b);
    printf("Result=%.2f\n",a-b);
}

void multiply()
{
    float a, b;
    printf("\nEnter two numbers: ");
    scanf("%f %f",&a,&b);
    printf("Result=%.2f\n",a*b);
}

void divide()
{
    float a, b;
    printf("\nEnter two numbers:");
    scanf("%f %f",&a,&b);

    if(b==0)
    {
        printf("Error: Division by zero not possible!\n");
    }
    else
    {
        printf("Result = %.2f\n", a/b);
    }
}

int main()
{
    int choice = 0;

    while(choice != 5)
    {
        printf("\n******  MENU DRIVEN CALCULATOR  ******");
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Division");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add();
                break;

            case 2:
                subtract();
                break;

            case 3:
                multiply();
                break;

            case 4:
                divide();
                break;

            case 5:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}