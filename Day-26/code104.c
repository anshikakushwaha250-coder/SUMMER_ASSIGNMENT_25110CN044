//Program to create quiz application
#include <stdio.h>
int main() {
    int score=0;
    int answer;
    printf("*** WELCOME TO QUIZ GAME ***\n");
    //Q1
    printf("\n1. What is the size of char data type in C?\n");
    printf("1) One\n2) Two\n3) Three\n4) Four\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer==1) {
        printf("Correct!\n");
        score++;
    } 
    else{
        printf("Wrong answer.The correct answer is 1. One\n");
    }

    // Q2
    printf("\n2. Which of the following is a logical operator?\n");
    printf("1) %\n2) ++\n3) =\n4) &&\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer==4) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer.The correct answer is 4. &&\n");
    }

    // Q3
    printf("\n3. Which function is used to find the length of the string?\n");
    printf("1) strcpy()\n2) strcat()\n3) strlen()\n4) strcmp()\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer==3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer.The correct answer is 3. strlen()\n");
    }

    // Q4
    printf("\n4. Which loop executes at least once?\n");
    printf("1) for\n2) while\n3) do-while\n4) None of these\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer==3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer.The correct answer is 3. do-while\n");
    }

    // Q5
    printf("\n5. Which function is used to read input from th user?\n");
    printf("1) printf()\n2) scanf()\n3) gets()\n4) puts()\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer==2) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer.The correct answer is 2.scanf()\n");
    }

    // Final score
    printf("\n*** QUIZ FINISHED ***\n");
    printf("Your score is: %d out of 5\n",score);
    return 0;
}