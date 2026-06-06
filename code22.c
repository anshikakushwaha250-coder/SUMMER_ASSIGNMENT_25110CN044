//Program to convert binary to decimal
#include <stdio.h>
#include <math.h>
int main(){
    int n,base=1,rem,decimal=0;
    printf("Enter a binary number");
    scanf("%d",&n);
    while (n>0){
        rem=n%10;
        decimal=decimal+rem*base;
        base=base*2;
        n=n/10;
    }
    printf("Decimal number=%d",decimal);
    return 0;
}