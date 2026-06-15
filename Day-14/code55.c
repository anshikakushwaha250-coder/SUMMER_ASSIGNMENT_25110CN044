//Program to second largest number
#include <stdio.h>
int main(){
    int i,n,count=0,ele;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int largest=arr[0],secondlargest=arr[0];
    for (i=1;i<n;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondlargest && arr[i]!=largest){
            secondlargest=arr[i];
        }
    }
    printf("Second largest number=%d",secondlargest);
    
    return 0;

}