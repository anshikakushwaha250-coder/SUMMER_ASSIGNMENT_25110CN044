//Program to find GCD of two numbers
#include <stdio.h>
int main(){
    int n1,n2,temp;
    printf("Enter two numbers\n");
    scanf("%d %d",&n1,&n2);
    while (n2!=0){
        int temp=n2;
        n2=n1%n2;
        n1=temp;
    }
    printf("GCD is %d\n",n1);
    return 0;   
}
