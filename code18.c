//Program to check strong number
#include <stdio.h>
int main(){
    int n,sum=0,rem,new;
    printf("Enter a number");
    scanf("%d",&n);
    new=n;
    while (n>0){
        rem=n%10;
        int i,fact=1;
        for (i=1;i<=rem;i++){
            fact=fact*i;
        }
        sum=sum+fact;
        n=n/10;
    }
    if (sum==new){
        printf("%d is a strong number",new);
    }
    else{
        printf("%d is not a strong number",new);
    }
    return 0;
}