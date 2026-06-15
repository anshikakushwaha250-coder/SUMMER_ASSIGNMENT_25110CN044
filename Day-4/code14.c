//Program to find nth fibonacci term
#include <stdio.h>
int main(){
    int a=0,b=1,i,n,next;
    printf("Enter no. of terms\n");
    scanf("%d",&n);
    if (n==1){
        printf("nth term is %d",a);
    }
    if (n==2){
        printf("nth term is %d",b);
    }
    else{
        for (i=1;i<=n;i++){
            next=a+b;
            a=b;
            b=next;
        }   
        printf("\nnth term is %d",b);    
    }
    return 0;
}
