//Write a program to reverse a number
#include <stdio.h>
int main() {
    int n,rem,new=0;
    printf("Enter a number");
    scanf("%d",&n);
    while (n>0){
        rem=n%10;
        new=new*10+rem;
        n=n/10;
    }
    printf("Reverse of the number is %d", new);
    return 0;
}