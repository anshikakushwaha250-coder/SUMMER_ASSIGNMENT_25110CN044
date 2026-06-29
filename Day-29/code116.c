//Program to create inventory management system
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Item
{
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inv[MAX];
int count = 0;

/* Add Item */
void addItem()
{
    printf("\nEnter Item ID: ");
    scanf("%d", &inv[count].id);
    getchar();

    printf("Enter Item Name: ");
    fgets(inv[count].name, 50, stdin);
    inv[count].name[strcspn(inv[count].name, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &inv[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &inv[count].price);

    count++;

    printf("\nItem Added Successfully!\n");
}

/* Display Items */
void displayItems()
{
    int i;

    if(count == 0)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\n===== INVENTORY LIST =====\n");

    for(i = 0; i < count; i++)
    {
        printf("\nItem %d", i + 1);
        printf("\nID       : %d", inv[i].id);
        printf("\nName     : %s", inv[i].name);
        printf("\nQuantity : %d", inv[i].quantity);
        printf("\nPrice    : %.2f\n", inv[i].price);
    }
}

/* Search Item */
void searchItem()
{
    int id, i, found = 0;

    printf("\nEnter Item ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(inv[i].id == id)
        {
            printf("\nItem Found!");
            printf("\nID       : %d", inv[i].id);
            printf("\nName     : %s", inv[i].name);
            printf("\nQuantity : %d", inv[i].quantity);
            printf("\nPrice    : %.2f\n", inv[i].price);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nItem not found!\n");
}

/* Update Item */
void updateItem()
{
    int id, i, choice;

    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(inv[i].id == id)
        {
            printf("\n1. Update Quantity");
            printf("\n2. Update Price");
            printf("\nEnter choice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("Enter new quantity: ");
                scanf("%d", &inv[i].quantity);
            }
            else if(choice == 2)
            {
                printf("Enter new price: ");
                scanf("%f", &inv[i].price);
            }
            else
            {
                printf("Invalid choice!\n");
            }

            printf("Item updated successfully!\n");
            return;
        }
    }

    printf("Item not found!\n");
}

/* Delete Item */
void deleteItem()
{
    int id, i, j;

    printf("\nEnter Item ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(inv[i].id == id)
        {
            for(j = i; j < count - 1; j++)
            {
                inv[j] = inv[j + 1];
            }

            count--;

            printf("Item deleted successfully!\n");
            return;
        }
    }

    printf("Item not found!\n");
}

/* Main Function */
int main()
{
    int choice = 0;

    while(choice != 6)
    {
        printf("\n***** INVENTORY MANAGEMENT SYSTEM *****");
        printf("\n1. Add Item");
        printf("\n2. Display Items");
        printf("\n3. Search Item");
        printf("\n4. Update Item");
        printf("\n5. Delete Item");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addItem();
                break;

            case 2:
                displayItems();
                break;

            case 3:
                searchItem();
                break;

            case 4:
                updateItem();
                break;

            case 5:
                deleteItem();
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