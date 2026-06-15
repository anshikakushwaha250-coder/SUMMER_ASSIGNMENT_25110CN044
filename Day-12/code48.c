//Program to write function for perfect number
#include <stdio.h>
int per(int);
int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    if (per(n)){
        printf("%d is a perfect number",n);
    }
    else{
        printf("%d is a not perfect number",n);
    }
    return 0;
}
int per(int n){
    int i,sum=0;
    for (i=1;i<n;i++){
        if (n%i==0){
            sum=sum+i;
        }
    }
    if (sum==n){
        return 1;
    }
    return 0;
}