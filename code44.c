//Program to write function to find a factorial
#include <stdio.h>
int factorial(int);
int main(){
    int n,fact;
    printf("Enter a number");
    scanf("%d",&n);
    if (n<0){
        printf("Factorial of negative number is not defined");
    }
    else{
        fact=factorial(n);
        printf("The factorial of %d is %d",n,fact);
    }
    return 0;
}
int factorial(int n){
    int i,fact=1;
    for(i=1;i<=n;i++){
        fact=fact*i;
    }
    return (fact);
}