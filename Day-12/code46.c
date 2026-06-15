//Program to write function for Armstrong
#include <stdio.h>
#include <math.h>
int armstrong(int);
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    if (armstrong(n)){
        printf("%d is armstrong",n);
    }
    else{
        printf("%d is not armstrong",n);
    }

    return 0;
}
int armstrong(int n){
    int arm=0,rem,original,temp,count=0;
    temp=n;
    original=n;
    while (n>0){
        rem=n%10;
        count++;
        n=n/10;
    }
    while (temp>0){
        rem=temp%10;
        arm=arm+pow(rem,count);
        temp=temp/10;
    }
    if (arm==original){
        return 1;
    }
    return 0;
}                


