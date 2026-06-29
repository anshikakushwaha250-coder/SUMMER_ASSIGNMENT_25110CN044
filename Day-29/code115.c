#include <stdio.h>
#include <string.h>

#define MAX 10
#define SIZE 100

char str[MAX][SIZE];
int n;

void inputStrings()
{
    int i;

    printf("\nEnter number of strings (max %d): ", MAX);
    scanf("%d", &n);

    if(n > MAX)
    {
        printf("Limit exceeded!\n");
        n = 0;
        return;
    }

    getchar();

    for(i = 0; i < n; i++)
    {
        printf("Enter string %d: ",  i+1);
        fgets(str[i], SIZE, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }

    printf("Strings stored successfully!\n");
}

void displayStrings()
{
    int i;

    if(n == 0)
    {
        printf("\nNo strings available!\n");
        return;
    }

    printf("\nStored Strings:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, str[i]);
    }
}

void stringLength()
{
    int i;

    printf("\nEnter string number (1-%d): ", n);
    scanf("%d", &i);

    if(i < 1 || i > n)
    {
        printf("Invalid choice!\n");
        return;
    }

    printf("Length = %lu\n", strlen(str[i - 1]));
}


void copyString()
{
    int i;
    char copy[SIZE];

    printf("\nEnter string number to copy (1-%d): ", n);
    scanf("%d", &i);

    if(i < 1 || i > n)
    {
        printf("Invalid choice!\n");
        return;
    }

    strcpy(copy, str[i - 1]);

    printf("Copied String: %s\n", copy);
}

void compareStrings()
{
    int a, b, result;

    printf("\nEnter first string number: ");
    scanf("%d", &a);

    printf("Enter second string number: ");
    scanf("%d", &b);

    if(a<1 || a>n || b<1 || b>n)
    {
        printf("Invalid choice!\n");
        return;
    }

    result = strcmp(str[a-1], str[b-1]);

    if(result == 0)
        printf("Strings are equal\n");
    else if(result > 0)
        printf("First string is greater\n");
    else
        printf("Second string is greater\n");
}

void concatenateStrings()
{
    int a, b;
    char result[SIZE*2];

    printf("\nEnter first string number: ");
    scanf("%d", &a);

    printf("Enter second string number: ");
    scanf("%d", &b);

    if(a<1 || a>n || b<1 || b>n)
    {
        printf("Invalid choice!\n");
        return;
    }

    strcpy(result, str[a-1]);
    strcat(result, str[b-1]);

    printf("Concatenated String: %s\n", result);
}

int main()
{
    int choice = 0;

    while(choice != 7)
    {
        printf("\n****** STRING OPERATIONS SYSTEM ******");
        printf("\n1. Input Strings");
        printf("\n2. Display Strings");
        printf("\n3. Find Length of String");
        printf("\n4. Copy String");
        printf("\n5. Compare Strings");
        printf("\n6. Concatenate Strings");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                inputStrings();
                break;

            case 2:
                displayStrings();
                break;

            case 3:
                stringLength();
                break;

            case 4:
                copyString();
                break;

            case 5:
                compareStrings();
                break;

            case 6:
                concatenateStrings();
                break;

            case 7:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}