//Program to create bank account system
#include <stdio.h>
#include <string.h>

struct Bank {
    int accNo;
    char name[50];
    float balance;
};

struct Bank account;

void createAccount() {
    printf("\nEnter Account Number: ");
    scanf("%d", &account.accNo);
    getchar();

    printf("Enter Account Holder Name: ");
    fgets(account.name, 50, stdin);
    account.name[strcspn(account.name, "\n")] = '\0';

    printf("Enter Initial Balance: ");
    scanf("%f", &account.balance);

    printf("\nAccount created successfully!\n");
}

void deposit() {
    float amount;

    printf("\nEnter Amount to Deposit: ");
    scanf("%f", &amount);

    account.balance += amount;

    printf("Amount deposited successfully.\n");
    printf("Current Balance: %.2f\n", account.balance);
}

void withdraw() {
    float amount;

    printf("\nEnter Amount to Withdraw: ");
    scanf("%f", &amount);

    if (amount <= account.balance) {
        account.balance -= amount;
        printf("Withdrawal successful.\n");
        printf("Remaining Balance: %.2f\n", account.balance);
    } 
    else {
        printf("Insufficient Balance!\n");
    }
}

void displayAccount() {
    printf("\n----- Account Details -----");
    printf("\nAccount Number : %d", account.accNo);
    printf("\nAccount Holder : %s", account.name);
    printf("\nBalance        : %.2f\n", account.balance);
}

int main() {
    int choice = 0;

    while (choice != 5) {
        printf("\n===== Bank Account Management System =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Display Account");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                displayAccount();
                break;

            case 5:
                printf("\nThank you! Exiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}