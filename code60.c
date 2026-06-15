//Program to move zeroes to end
#include <stdio.h>
int main(){
    int n,i,j=0,temp;
    printf("Enter size of an array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements\n");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++){
        if (arr[i]!=0){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
    }
    printf("Array after moving zeroes to end\n");
    for (i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}    