//Program to Recursive factorial
#include <stdio.h>
int factorial (int);
int main(){
    int n,result;
    printf("Enter a number");
    scanf("%d",&n);
    result=factorial(n);
    printf("The factorial of %d =%d",n,result);
    return 0;
}
int factorial(int n){
    if (n==0){
        return 1;
    }
    else{
        return(n*factorial(n-1));
    }
}