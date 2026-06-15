//Program to rotate array right
#include <stdio.h>
int main(){
    int n,i,temp;
    printf("Enter size of an array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements\n");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    temp=arr[n-1];
    for (i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    printf("Array after right rotation\n");
    for (i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}    