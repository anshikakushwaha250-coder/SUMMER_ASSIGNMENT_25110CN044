//Program to Binary Search
#include <stdio.h>
int main(){
    int arr[100],n,x,mid,low,high;
    int i,j,temp,flag=0;
    printf("Enter no. of elements");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for (i=0;i<=n-1;i++){
        scanf("%d",&arr[i]);
    }
    //Sorting array before binary search
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array is: \n");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
   
    //Binary Search
    printf("\nEnter element to search");
    scanf("%d",&x);
    low=0;
    high=n-1;
    while (low<=high){
        mid=(low+high)/2;
        if (arr[mid]==x){
            flag=1;
            break;
        }
        else if (arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if (flag==1){
        printf("Element present at %d",mid+1);
    }
    else{
        printf("Unsuccessful Search");
    }
    return 0;
}