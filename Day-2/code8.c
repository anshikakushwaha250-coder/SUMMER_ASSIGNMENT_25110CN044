//Program to check if the number is palindrome or not
#include <stdio.h>
int main() {
    int n,rem,new=0,number;
    printf("Enter a number");
    scanf("%d",&n);
    number=n;
    while (n>0){
        rem=n%10;
        new=new*10+rem;
        n=n/10;
    }
    if (number==new){
        printf("%d is palindrome\n", number);
    }
    else{
        printf("%d is not palindrome\n", number);
    }
    return 0;
}