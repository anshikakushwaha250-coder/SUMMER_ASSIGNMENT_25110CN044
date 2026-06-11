//Program to write function to check prime
#include <stdio.h>
int prime(int);
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    if (prime(n))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
    return 0;
}
int prime(int n){
    int i;
    if (n<=1){
        return 0;
    }
    for (i=2;i<=n/2;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}