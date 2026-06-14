//Program to frequency of an element
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
    printf("Enter elements to search");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if (arr[i]==ele){
            count++;
        }
    }
    if (count==0){
        printf("Element not found");
    }   
    else{
        printf("Frequency of %d =%d",ele,count);
    }
    return 0;

}