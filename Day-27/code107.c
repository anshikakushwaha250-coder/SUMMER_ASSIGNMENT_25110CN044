//Program to create salary management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char id[10];
    char name[50];
    float basic,hra,da,gross;
};

void addRecord() {
    FILE *fp=fopen("salary.dat","ab");
    struct Employee e;

    if (fp==NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%s",e.id);
    getchar();

    printf("Enter Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f",&e.basic);

    printf("Enter HRA: ");
    scanf("%f",&e.hra);

    printf("Enter DA: ");
    scanf("%f",&e.da);

    e.gross=e.basic + e.hra + e.da;

    fwrite(&e,sizeof(e),1,fp);
    fclose(fp);

    printf("Salary record added successfully!\n");
}

void displayRecords() {
    FILE *fp = fopen("salary.dat","rb");
    struct Employee e;

    if (fp==NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Salary Records ---\n");

    while (fread(&e, sizeof(e), 1, fp)) {
        printf("ID: %s | Name: %s | Basic: %.2f | HRA: %.2f | DA: %.2f | Gross: %.2f\n",e.id, e.name, e.basic, e.hra, e.da, e.gross);
    }
    fclose(fp);
} 

void searchRecord() {
    FILE *fp = fopen("salary.dat","rb");
    struct Employee e;
    char id[10];
    int found = 0;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Employee ID to search: ");
    scanf("%s", id);

    while (fread(&e,sizeof(e),1,fp)) {
        if (strcmp(e.id, id) == 0) {
            printf("Found: %s | %s | Gross: %.2f\n",e.id, e.name, e.gross);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found.\n");

    fclose(fp);
}

void updateRecord() {
    FILE *fp = fopen("salary.dat", "rb+");
    struct Employee e;
    char id[10];
    int found = 0;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%s",id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (strcmp(e.id,id) == 0) {

            getchar();
            printf("Enter new name: ");
            fgets(e.name,sizeof(e.name),stdin);
            e.name[strcspn(e.name,"\n")]='\0';

            printf("Enter new Basic:");
            scanf("%f",&e.basic);

            printf("Enter new HRA: ");
            scanf("%f",&e.hra);

            printf("Enter new DA: ");
            scanf("%f",&e.da);
            e.gross=e.basic + e.hra + e.da;
            fseek(fp, -sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, fp);
            found = 1;
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Record not found.\n");

    fclose(fp);
}
 
void deleteRecord() {
    FILE *fp=fopen("salary.dat","rb");
    FILE *temp=fopen("temp.dat","wb");

    struct Employee e;
    char id[10];
    int found = 0;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%s", id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (strcmp(e.id, id) != 0) {
            fwrite(&e, sizeof(e), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("salary.dat");
    rename("temp.dat", "salary.dat");

    if (found)
        printf("Record deleted successfully!\n");
    else
        printf("Record not found.\n");
}

/* MAIN FUNCTION */
int main() {
    int choice;

    while (1) {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addRecord();
                break;
            case 2: displayRecords(); 
                break;
            case 3: searchRecord(); 
                break;
            case 4: updateRecord(); 
                break;
            case 5: deleteRecord(); 
                break;
            case 6: exit(0);
            
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}