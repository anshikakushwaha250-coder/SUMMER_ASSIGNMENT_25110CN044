//Program to recursive fibonacci
#include <stdio.h>
int fib(int);
int main(){
    int i,n;
    printf("Enter no. of terms");
    scanf("%d",&n);
    for (i=0;i<=n-1;i++){
        printf("%d  ",fib(i));
    }
    return 0;
}
int fib(int i){
    if (i==0){
        return 0;
    }
    if (i==1){
        return 1;
    }
    return (fib(i-1)+fib(i-2));
}