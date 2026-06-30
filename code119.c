//Program to create mini employee management system
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int empID[MAX], age[MAX], salary[MAX];
    char name[MAX][50], department[MAX][30];
    int count = 0, choice, i, j, id, found;

    while (1) {
        printf("\n===== MINI EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (count == MAX) {
                printf("Employee record is full!\n");
                break;
            }

            printf("\nEnter Employee ID: ");
            scanf("%d", &empID[count]);

            printf("Enter Employee Name: ");
            scanf(" %[^\n]", name[count]);

            printf("Enter Department: ");
            scanf(" %[^\n]", department[count]);

            printf("Enter Age: ");
            scanf("%d", &age[count]);

            printf("Enter Salary: ");
            scanf("%d", &salary[count]);

            count++;
            printf("Employee added successfully.\n");
            break;

        case 2:
            if (count == 0) {
                printf("No employee records found.\n");
                break;
            }

            printf("\n--------------------------------------------------------------------------\n");
            printf("ID\tName\t\tDepartment\tAge\tSalary\n");
            printf("--------------------------------------------------------------------------\n");

            for (i = 0; i < count; i++) {
                printf("%d\t%-15s%-15s%d\t%d\n",
                       empID[i], name[i], department[i], age[i], salary[i]);
            }
            break;

        case 3:
            printf("Enter Employee ID to search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (empID[i] == id) {
                    printf("\nEmployee Found\n");
                    printf("ID         : %d\n", empID[i]);
                    printf("Name       : %s\n", name[i]);
                    printf("Department : %s\n", department[i]);
                    printf("Age        : %d\n", age[i]);
                    printf("Salary     : %d\n", salary[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 4:
            printf("Enter Employee ID to update: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (empID[i] == id) {

                    printf("Enter New Name: ");
                    scanf(" %[^\n]", name[i]);

                    printf("Enter New Department: ");
                    scanf(" %[^\n]", department[i]);

                    printf("Enter New Age: ");
                    scanf("%d", &age[i]);

                    printf("Enter New Salary: ");
                    scanf("%d", &salary[i]);

                    printf("Employee record updated successfully.\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 5:
            printf("Enter Employee ID to delete: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (empID[i] == id) {

                    for (j = i; j < count - 1; j++) {
                        empID[j] = empID[j + 1];
                        age[j] = age[j + 1];
                        salary[j] = salary[j + 1];
                        strcpy(name[j], name[j + 1]);
                        strcpy(department[j], department[j + 1]);
                    }

                    count--;
                    printf("Employee record deleted successfully.\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 6:
            printf("Thank you for using the Mini Employee Management System!\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}