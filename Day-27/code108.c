//Program to create marksheet generation system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBJECTS 5

struct Student {
    int roll;
    char name[50];
    int marks[SUBJECTS];
    int total;
    float percentage;
    char grade[5];
};

char subjects[SUBJECTS][20] = {"Math", "Physics", "Chemistry", "English", "CS"};

void calculate(struct Student *s) {
    s->total = 0;

    for (int i=0;i<SUBJECTS;i++) {
        s->total += s->marks[i];
    }

    s->percentage = (float)s->total / SUBJECTS;

    if (s->percentage >= 90)
        strcpy(s->grade, "A+");
    else if (s->percentage >= 75)
        strcpy(s->grade, "A");
    else if (s->percentage >= 60)
        strcpy(s->grade, "B");
    else if (s->percentage >= 40)
        strcpy(s->grade, "C");
    else
        strcpy(s->grade, "F");
}

// ADD STUDENT
void addStudent() {
    FILE *fp = fopen("marksheet.dat", "ab");
    struct Student s;

    printf("\nEnter Roll No: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks in %s: ", subjects[i]);
        scanf("%d", &s.marks[i]);
    }

    calculate(&s);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Record added successfully!\n");
}

// DISPLAY ALL STUDENTS
void displayStudents() {
    FILE *fp = fopen("marksheet.dat", "rb");
    struct Student s;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n==================== MARKSHEET RECORDS ====================\n");

    while (fread(&s, sizeof(s), 1, fp)) {

        printf("\n----------------------------------------------------------\n");
        printf("Roll No : %-10d Name : %-20s\n", s.roll, s.name);
        printf("----------------------------------------------------------\n");

        printf("%-15s %-10s\n", "Subject", "Marks");
        printf("----------------------------------------------------------\n");

        for (int i = 0; i < SUBJECTS; i++) {
            printf("%-15s %-10d\n", subjects[i], s.marks[i]);
        }

        printf("----------------------------------------------------------\n");
        printf("Total     : %-10d\n", s.total);
        printf("Percentage: %-10.2f%%\n", s.percentage);
        printf("Grade     : %-10s\n", s.grade);
        printf("==========================================================\n");
    }

    fclose(fp);
}

// SEARCH STUDENT
void searchStudent() {
    FILE *fp = fopen("marksheet.dat", "rb");
    struct Student s;
    int roll, found = 0;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {

            printf("\n==================== STUDENT MARKSHEET ====================\n");
            printf("Roll No : %-10d Name : %-20s\n", s.roll, s.name);
            printf("----------------------------------------------------------\n");

            printf("%-15s %-10s\n", "Subject", "Marks");
            printf("----------------------------------------------------------\n");

            for (int i = 0; i < SUBJECTS; i++) {
                printf("%-15s %-10d\n", subjects[i], s.marks[i]);
            }

            printf("----------------------------------------------------------\n");
            printf("Total     : %-10d\n", s.total);
            printf("Percentage: %-10.2f%%\n", s.percentage);
            printf("Grade     : %-10s\n", s.grade);
            printf("==========================================================\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

// UPDATE STUDENT
void updateStudent() {
    FILE *fp = fopen("marksheet.dat", "rb+");
    struct Student s;
    int roll, found = 0;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll No to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {

            printf("\n--- UPDATE STUDENT ---\n");

            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);

            for (int i = 0; i < SUBJECTS; i++) {
                printf("Enter marks in %s: ", subjects[i]);
                scanf("%d", &s.marks[i]);
            }

            calculate(&s);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("Updated Successfully!\n");
            printf("New Percentage: %.2f%% | Grade: %s\n",
                   s.percentage, s.grade);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

// DELETE STUDENT
void deleteStudent() {
    FILE *fp = fopen("marksheet.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    struct Student s;
    int roll, found = 0;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll No to delete: ");
    scanf("%d",&roll);

    while (fread(&s,sizeof(s),1,fp)) {
        if (s.roll != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("marksheet.dat");
    rename("temp.dat","marksheet.dat");

    if (found)
        printf("Record deleted successfully!\n");
    else
        printf("Student not found!\n");
}

// MAIN MENU
int main() {
    int choice;

    while (1) {
        printf("\n===== MARKSHEET SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); 
                break;
            case 2: displayStudents(); 
                break;
            case 3: searchStudent(); 
                break;
            case 4: updateStudent(); 
                break;
            case 5: deleteStudent(); 
                break;
            case 6: exit(0);

            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
