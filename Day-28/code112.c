//Program to create contact management system
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contact[MAX];
int count = 0;

/* Convert string to lowercase */
void toLowerStr(char str[])
{
    int i;
    for(i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void addContact()
{
    printf("\nEnter Name: ");
    getchar();
    fgets(contact[count].name, 50, stdin);
    contact[count].name[strcspn(contact[count].name, "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(contact[count].phone, 15, stdin);
    contact[count].phone[strcspn(contact[count].phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(contact[count].email, 50, stdin);
    contact[count].email[strcspn(contact[count].email, "\n")] = '\0';

    count++;

    printf("\nContact Added Successfully!\n");
}

void displayContacts()
{
    int i;

    if(count == 0)
    {
        printf("\nNo Contacts Found!\n");
        return;
    }

    printf("\n====== Contact List ======\n");

    for(i = 0; i < count; i++)
    {
        printf("\nContact %d", i + 1);
        printf("\nName  : %s", contact[i].name);
        printf("\nPhone : %s", contact[i].phone);
        printf("\nEmail : %s\n", contact[i].email);
    }
}

void searchContact()
{
    char search[50];
    int i, found = 0;

    printf("\nEnter Name to Search: ");
    getchar();
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = '\0';

    toLowerStr(search);

    for(i = 0; i < count; i++)
    {
        char temp[50];
        strcpy(temp, contact[i].name);

        toLowerStr(temp);

        if(strcmp(temp, search) == 0)
        {
            printf("\nContact Found!");
            printf("\nName  : %s", contact[i].name);
            printf("\nPhone : %s", contact[i].phone);
            printf("\nEmail : %s\n", contact[i].email);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nContact Not Found!\n");
    }
}

void deleteContact()
{
    int index, i;

    if(count == 0)
    {
        printf("\nNo Contacts to Delete!\n");
        return;
    }

    displayContacts();

    printf("\nEnter Contact Number to Delete: ");
    scanf("%d", &index);

    if(index < 1 || index > count)
    {
        printf("\nInvalid Contact Number!\n");
        return;
    }

    for(i = index - 1; i < count - 1; i++)
    {
        contact[i] = contact[i + 1];
    }

    count--;

    printf("\nContact Deleted Successfully!\n");
}

int main()
{
    int choice = 0;

    while(choice != 5)
    {
        printf("\n==============================");
        printf("\n Contact Management System");
        printf("\n==============================");
        printf("\n1. Add Contact");
        printf("\n2. Display Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Delete Contact");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}