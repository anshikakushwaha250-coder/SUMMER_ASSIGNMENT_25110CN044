//Program to find product of digits of a number
#include <stdio.h>
int main() {
    int n,rem,num,product=1;
    printf("Enter a number");
    scanf("%d",&n);
    num=n;
    while (n>0){
        rem=n%10;
        product=product*rem;
        n=n/10;
    }
    printf("Product of digits of number %d=%d", num, product);
    return 0;
}