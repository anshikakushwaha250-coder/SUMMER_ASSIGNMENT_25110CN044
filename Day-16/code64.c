//Program to remove duplicates from an array
#include <stdio.h>
int main(){
    int i,j,k,n;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                for(k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
            }
        }
    }
    printf("Array after removing duplicates\n");
    for (i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}    