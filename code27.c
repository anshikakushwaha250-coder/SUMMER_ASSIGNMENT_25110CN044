//Program to recursive sum of digits
#include <stdio.h>
int sum(int);
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    printf("The sum of digits of %d is %d",n,sum(n));
    return 0;
}
int sum(int n){
    if (n==0){
        return 0;
    }
    else{
        return (n%10+sum(n/10));
    }
}
    

