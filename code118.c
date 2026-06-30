//Program to create mini library system
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int bookID[MAX], issued[MAX];
    char title[MAX][50], author[MAX][50];
    int count = 0, choice, i, j, id, found;

    while (1) {
        printf("\n===== MINI LIBRARY SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (count == MAX) {
                printf("Library is full!\n");
                break;
            }

            printf("Enter Book ID: ");
            scanf("%d", &bookID[count]);

            printf("Enter Book Title: ");
            scanf(" %[^\n]", title[count]);

            printf("Enter Author Name: ");
            scanf(" %[^\n]", author[count]);

            issued[count] = 0;
            count++;

            printf("Book added successfully.\n");
            break;

        case 2:
            if (count == 0) {
                printf("No books available.\n");
                break;
            }

            printf("\n-------------------------------------------------------------\n");
            printf("ID\tTitle\t\t\tAuthor\t\tStatus\n");
            printf("-------------------------------------------------------------\n");

            for (i = 0; i < count; i++) {
                printf("%d\t%-20s%-20s%s\n",
                       bookID[i], title[i], author[i],
                       issued[i] ? "Issued" : "Available");
            }
            break;

        case 3:
            printf("Enter Book ID to search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (bookID[i] == id) {
                    printf("\nBook Found\n");
                    printf("ID     : %d\n", bookID[i]);
                    printf("Title  : %s\n", title[i]);
                    printf("Author : %s\n", author[i]);
                    printf("Status : %s\n",
                           issued[i] ? "Issued" : "Available");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
            break;

        case 4:
            printf("Enter Book ID to issue: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (bookID[i] == id) {
                    if (issued[i])
                        printf("Book is already issued.\n");
                    else {
                        issued[i] = 1;
                        printf("Book issued successfully.\n");
                    }
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
            break;

        case 5:
            printf("Enter Book ID to return: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (bookID[i] == id) {
                    if (!issued[i])
                        printf("Book is already available.\n");
                    else {
                        issued[i] = 0;
                        printf("Book returned successfully.\n");
                    }
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
            break;

        case 6:
            printf("Enter Book ID to delete: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (bookID[i] == id) {

                    for (j = i; j < count - 1; j++) {
                        bookID[j] = bookID[j + 1];
                        issued[j] = issued[j + 1];
                        strcpy(title[j], title[j + 1]);
                        strcpy(author[j], author[j + 1]);
                    }

                    count--;
                    printf("Book deleted successfully.\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
            break;

        case 7:
            printf("Thank you for using the Mini Library System!\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}