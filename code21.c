//Program to convert decimal to binary
#include <stdio.h>
int main(){
    int n,binary=0,temp=1;
    printf("Enter a decimal number");
    scanf("%d",&n);
    while (n>0){
        binary=binary+(n%2)*temp;
        n=n/2;
        temp=temp*10;
    }
    printf("Binary number=%d",binary);
    return 0;
}