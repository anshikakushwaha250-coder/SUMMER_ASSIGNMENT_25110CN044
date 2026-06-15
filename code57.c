//Program to reverse array
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
    for(i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    printf("Reversed array is:\n");
    for (i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}