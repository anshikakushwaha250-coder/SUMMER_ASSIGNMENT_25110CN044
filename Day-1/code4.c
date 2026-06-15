//Program to count digits of a number
#include <stdio.h>
int main() {
    int n,count=0,rem;
    printf("Enter a number");
    scanf("%d",&n);
    int new=n;
    while (n>0){
        rem=n%10;
        count++;
        n=n/10;
    }
    printf("The number of digits in %d is %d",new,count);
    return 0;
}