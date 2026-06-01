//Program to print multiplication table of a given number
#include <stdio.h>
int main(){
    int n,i,product=0;
    printf("Enter a number");
    scanf("%d",&n);
    for (i=1;i<=10;i++){
        product=n*i;
        printf("%d x %d = %d\n",n,i,product);
    }
    return 0;
}