//Program to find pair with given sum
#include <stdio.h>
int main(){
    int i,j,n,sum,found=0;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter required sum:");
    scanf("%d",&sum);
    for(i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (arr[i]+arr[j]==sum){
                printf("Pair found:%d and %d\n",arr[i],arr[j]);
                found=1;
            }
        }
    }
    if (found!=1){
        printf("No pair found");
    }
    return 0;
}    