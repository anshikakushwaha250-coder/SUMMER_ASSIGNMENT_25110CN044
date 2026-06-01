//Program to calculate sum of first n natural numbers
#include <stdio.h>
int main() {
    int n,i,sum=0;
    printf("Enter number of terms");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        sum=sum+i;
    }
    printf("The sum %d natural numbers is %d",n,sum);
    return 0;
}