//Program to recursive reverse number
#include <stdio.h>
int reverse(int n);
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    printf("The reverse of %d is %d",n,reverse(n));
    return 0;
}
int rev=0;
int reverse(int n) {
    if (n == 0){
        return rev;
    }    
    rev=rev*10+ n%10;
    return reverse(n/10);
}