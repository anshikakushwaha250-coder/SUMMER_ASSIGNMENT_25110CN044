//Program to create employee management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};
void addEmployee() {
    FILE *fp = fopen("employees.dat", "ab");
    struct Employee e;

    printf("Enter Employee ID:");
    scanf("%d",&e.id);

    printf("Enter Name:");
    scanf(" %[^\n]",e.name);

    printf("Enter Salary:");
    scanf("%f",&e.salary);

    fwrite(&e,sizeof(e),1,fp);
    fclose(fp);

    printf("Employee added successfully!\n");
}

void displayEmployees() {
    FILE *fp=fopen("employees.dat","rb");
    struct Employee e;

    if (fp==NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Employee Records ---\n");

    while (fread(&e,sizeof(e),1,fp)) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",e.id,e.name,e.salary);
    }
    fclose(fp);
}

void searchEmployee() {
    FILE *fp = fopen("employees.dat", "rb");
    struct Employee e;
    int id, found = 0;

    if (fp==NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Employee ID to search: ");
    scanf("%d",&id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.id == id) {
            printf("Found: ID: %d | Name: %s | Salary: %.2f\n",e.id, e.name, e.salary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");
    fclose(fp);
}

void updateEmployee() {
    FILE *fp = fopen("employees.dat", "rb+");
    struct Employee e;
    int id, found = 0;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.id == id) {

            printf("Enter new name: ");
            scanf(" %[^\n]", e.name);

            printf("Enter new salary: ");
            scanf("%f", &e.salary);

            fseek(fp, -sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, fp);

            found = 1;
            printf("Employee updated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");

    fclose(fp);
}

void deleteEmployee() {
    FILE *fp = fopen("employees.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    struct Employee e;
    int id, found = 0;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.id != id) {
            fwrite(&e, sizeof(e), 1, temp);
        } 
        else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employees.dat");
    rename("temp.dat","employees.dat");

    if (found)
        printf("Employee deleted successfully!\n");
    else
        printf("Employee not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); 
                break;
            case 2: displayEmployees(); 
                break;
            case 3: searchEmployee(); 
                break;
            case 4: updateEmployee(); 
                break;
            case 5: deleteEmployee(); 
                break;
            case 6: exit(0);

            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}