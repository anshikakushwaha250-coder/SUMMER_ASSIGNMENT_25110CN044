//Program to write function for palindrome
#include <stdio.h>
int palindrome(int);
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    if (palindrome(n)){
        printf("%d is palindrome",n);
    }
    else{
        printf("%d is not palindrome",n);
    }

    return 0;
}
int palindrome(int n){
    int rev=0,rem,original;
    original=n;
    while (n>0){
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    if (rev==original){
        return 1;
    }
    return 0;
}                


