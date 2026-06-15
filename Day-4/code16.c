//Program to print Armstrong number in a range
#include <stdio.h>
#include <math.h>
int main(){
    int n1,n2,i;
    printf("Enter a range\n");
    printf("Enter first number\n");
    scanf ("%d",&n1);
    printf("Enter second number\n");
    scanf ("%d",&n2);
    printf("Armstrong numbers between range %d and %d are: ",n1,n2);
    for (i=n1;i<=n2;i++){
        int count=0,arm=0,rem,number,new;
        new=i;
        number=i;
        while (new>0){
            rem=new%10;
            count++;
            new=new/10;
        }
        new=i;
        while(new>0){
            rem=new%10;
            arm=arm+pow(rem,count);
            new=new/10;
        }
        if (number==arm){
            printf("%d ",number);
        }
    }    
    return 0;
}