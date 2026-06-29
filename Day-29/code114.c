//Program to create menu-driven array operations system
#include <stdio.h>
#define MAX 100

int arr[MAX], n = 0;

void insert()
{
    int i;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    if(n > MAX)
    {
        printf("Limit exceeded!\n");
        n = 0;
        return;
    }

    printf("Enter elements:\n");
    for(i=0;i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array inserted successfully!\n");
}

void display()
{
    int i;
    if(n == 0)
    {
        printf("\nArray is empty!\n");
        return;
    }

    printf("\nArray elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search()
{
    int i, key, found = 0;

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Element not found!\n");
}

void update()
{
    int i, pos, value;

    if(n == 0)
    {
        printf("\nArray is empty!\n");
        return;
    }

    printf("\nEnter position to update (1-%d): ", n);
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);
    arr[pos - 1] = value;

    printf("Element updated successfully!\n");
}

void deleteElement()
{
    int i, pos;

    if(n == 0)
    {
        printf("\nArray is empty!\n");
        return;
    }

    printf("\nEnter position to delete (1-%d): ", n);
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return;
    }

    for(i=pos-1; i< n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
    printf("Element deleted successfully!\n");
}

int main()
{
    int choice = 0;
    while(choice != 6)
    {
        printf("\n==============================");
        printf("\n ARRAY OPERATIONS MENU");
        printf("\n==============================");
        printf("\n1. Insert Array");
        printf("\n2. Display Array");
        printf("\n3. Search Element");
        printf("\n4. Update Element");
        printf("\n5. Delete Element");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                update();
                break;

            case 5:
                deleteElement();
                break;

            case 6:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}