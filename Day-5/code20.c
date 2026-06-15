//Program to find largest prime factor of a number
#include <stdio.h>
int main(){
    int n,i,j,largest=0;
    printf("Enter a number");
    scanf("%d",&n);
    for (i=2;i<=n/2;i++){
        if (n%i==0){
            int prime=1;
            for (j=2;j<i;j++){
                if (i%j==0){
                    prime=0;
                    break;
                }
            }
            if (prime==1){
                largest=i;
            }   
        }
    }
    if (largest==0){
        largest=n;
    }    
    printf("Largest prime factor of %d = %d",n, largest);    
    return 0;
}