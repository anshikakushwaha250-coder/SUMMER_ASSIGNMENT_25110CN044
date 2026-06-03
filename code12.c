//Program to find LCM of two numbers
#include <stdio.h>
int main(){
    int n1,n2,max;
    printf("Enter two numbers\n");
    scanf("%d %d",&n1,&n2);
    if (n1>n2){
        max=n1;
    }
    else{
        max=n2;
    }
    while (1){
        if (max%n1==0 && max%n2==0){
            printf("LCM is %d\n",max);
            break;
        }
        max++;
    } 
    return 0;
}