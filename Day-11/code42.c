//Program to write function of maximum number
#include <stdio.h>
int max(int,int);
int main(){
    int x,y,result;
    printf("Enter two numbers");
    scanf("%d %d",&x,&y);
    result=max(x,y);
    printf("The greater number is %d",result);
    return 0;
}
int max(int x,int y){
    int max;
    if (x>y){
        return x;
    }
    else{
        return y;
    }
}