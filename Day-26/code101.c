//Program to create number guessing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL)); //random number is generated each time the program runs.
    int guess=0,tries=0,min=1,max=100;
    int answer=(rand()%(max-min+1))+min;//To generate a random number between min and max

    printf("***NUMBER GUESSING GAME***\n");
    printf("Guess a number between 1 to 100\n");

    while (guess!=answer){
        printf("Enter your guess");
        scanf("%d",&guess);
        tries++;
        if (guess<answer){
            printf("Too low! Try again.\n");
        } 
        else if (guess>answer){
            printf("Too high!Try again.\n");
        }
        else {
            printf("Congratulations! You guessed the correct number: %d\n",answer);
        }
    }    
    printf("It took %d tries",tries);
    return 0;
}

   