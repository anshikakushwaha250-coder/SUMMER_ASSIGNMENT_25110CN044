//Program to print prime numbers in a range
#include <stdio.h>
int main(){
    int n1,n2,i,j;
    printf("Enter the range\n");
    printf("Enter the starting number\n");
    scanf("%d",&n1);
    printf("Enter the ending number\n");
    scanf("%d",&n2);
    printf("Prime numbers are between range  %d and %d \n",n1,n2);
    for (i=n1;i<=n2;i++){
        if (i<=1){
            continue;    
        }
        int prime=1;
        for (j=2;j<=i/2;j++){
            if (i%j==0){
                prime=0;
                break;
            }
        }
        if (prime==1){
            printf("%d ",i);
        }
    }
    return 0;
}
