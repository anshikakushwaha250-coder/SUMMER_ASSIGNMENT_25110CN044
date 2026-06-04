//Program to generate Fibonacci Series
#include <stdio.h>
int main(){
    int a=0,b=1,next,i,n;
    printf("Enter no. of terms\n");
    scanf("%d",&n);
    printf("Fibonacci series: \n");
    for (i=1;i<=n;i++){
        printf("%d ",a);
        next=a+b;
        a=b;
        b=next;
    }
    return 0;
}