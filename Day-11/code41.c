//Program to write function to find sum of two numbers
#include <stdio.h>
int sum(int,int);
int main(){
    int x,y,result;
    printf("Enter two numbers");
    scanf("%d %d",&x,&y);
    result=sum(x,y);
    printf("The sum of %d and %d is %d",x,y,result);
    return 0;
}
int sum(int x,int y){
    int sum;
    sum=x+y;
    return (sum);
}
