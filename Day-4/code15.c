//Program to check Armstrong number
#include <stdio.h>
#include <math.h>
int main(){
    int n,rem,count=0,arm=0,new,number;
    printf("Enter a number");
    scanf ("%d",&n);
    new=n;
    number=n;
    while (n>0){
        rem=n%10;
        count++;
        n=n/10;
    }
    while(new>0){
        rem=new%10;
        arm=arm+pow(rem,count);
        new=new/10;
    }
    if (number==arm){
        printf("\n %d is Armstrong",number);
    }
    else{
        printf("\n %d is not Armstrong",number);
    }
    return 0;
}