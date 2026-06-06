//Program to find x^n without pow()
#include <stdio.h>
int main(){
    int base,power,ans=1,i;
    printf("Enter base\n");
    scanf("%d",&base);
    printf("\nEnter power");
    scanf("%d",&power);
    for (i=1;i<=power;i++){
        ans=ans*base;
    }
    printf("%d^%d=%d",base,power,ans);
    return 0;
}    