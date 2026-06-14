//Program to find duplicates in an array
#include <stdio.h>
int main(){
    int i,j,n;
    printf("Enter size of an array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements\n");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Duplicate elements are:\n");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                printf("%d\t",arr[i]);
                break;
            }
        }
    }    
    return 0;    
}