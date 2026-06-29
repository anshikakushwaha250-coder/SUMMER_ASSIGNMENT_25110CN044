//Program to create library management system
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;
};

struct Book books[MAX];
int count = 0;

void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);
    getchar();

    printf("Enter Book Title: ");
    fgets(books[count].title, 50, stdin);
    books[count].title[strcspn(books[count].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(books[count].author, 50, stdin);
    books[count].author[strcspn(books[count].author, "\n")] = '\0';

    books[count].issued = 0;
    count++;

    printf("Book added successfully!\n");
}

void displayBooks() {
    int i;

    if (count == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n----- Book List -----\n");

    for (i = 0; i < count; i++) {
        printf("\nBook ID : %d", books[i].id);
        printf("\nTitle   : %s", books[i].title);
        printf("\nAuthor  : %s", books[i].author);
        printf("\nStatus  : %s\n",books[i].issued ? "Issued" : "Available");
    }
}

void searchBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found");
            printf("\nBook ID : %d", books[i].id);
            printf("\nTitle   : %s", books[i].title);
            printf("\nAuthor  : %s", books[i].author);
            printf("\nStatus  : %s\n",books[i].issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");
}

void issueBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 0) {
                books[i].issued = 1;
                printf("Book issued successfully.\n");
            } 
            else {
                printf("Book is already issued.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");
}

void returnBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 1) {
                books[i].issued = 0;
                printf("Book returned successfully.\n");
            } 
            else {
                printf("Book was not issued.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");
}

int main() {
    int choice = 0;

    while (choice != 6) {
        printf("\n===== Library Management System =====");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("\nThank you! Exiting...\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}