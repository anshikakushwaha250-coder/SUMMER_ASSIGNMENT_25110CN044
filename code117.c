//Program to create student record system using arrays and strings
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int roll[MAX], age[MAX];
    char name[MAX][50];
    char studentClass[MAX][20];
    int count = 0, choice, i, j, r, found;

    while (1) {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (count == MAX) {
                printf("Student record is full!\n");
                break;
            }

            printf("\nEnter Roll Number: ");
            scanf("%d", &roll[count]);

            printf("Enter Name: ");
            scanf(" %[^\n]", name[count]);

            printf("Enter Class: ");
            scanf(" %[^\n]", studentClass[count]);

            printf("Enter Age: ");
            scanf("%d", &age[count]);

            count++;
            printf("Student record added successfully.\n");
            break;

        case 2:
            if (count == 0) {
                printf("No records found.\n");
                break;
            }

            printf("\n---------------------------------------------------------------\n");
            printf("Roll\tName\t\t\tClass\t\tAge\n");
            printf("---------------------------------------------------------------\n");

            for (i = 0; i < count; i++) {
                printf("%d\t%-20s%-15s%d\n",
                       roll[i], name[i], studentClass[i], age[i]);
            }
            break;

        case 3:
            printf("Enter Roll Number to search: ");
            scanf("%d", &r);

            found = 0;
            for (i = 0; i < count; i++) {
                if (roll[i] == r) {
                    printf("\nStudent Found\n");
                    printf("Roll  : %d\n", roll[i]);
                    printf("Name  : %s\n", name[i]);
                    printf("Class : %s\n", studentClass[i]);
                    printf("Age   : %d\n", age[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Student not found.\n");
            break;

        case 4:
            printf("Enter Roll Number to update: ");
            scanf("%d", &r);

            found = 0;
            for (i = 0; i < count; i++) {
                if (roll[i] == r) {

                    printf("Enter New Name: ");
                    scanf(" %[^\n]", name[i]);

                    printf("Enter New Class: ");
                    scanf(" %[^\n]", studentClass[i]);

                    printf("Enter New Age: ");
                    scanf("%d", &age[i]);

                    printf("Record updated successfully.\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Student not found.\n");
            break;

        case 5:
            printf("Enter Roll Number to delete: ");
            scanf("%d", &r);

            found = 0;
            for (i = 0; i < count; i++) {
                if (roll[i] == r) {

                    for (j = i; j < count - 1; j++) {
                        roll[j] = roll[j + 1];
                        age[j] = age[j + 1];
                        strcpy(name[j], name[j + 1]);
                        strcpy(studentClass[j], studentClass[j + 1]);
                    }

                    count--;
                    printf("Record deleted successfully.\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Student not found.\n");
            break;

        case 6:
            printf("Thank you for using the Student Record System!\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}