//Program to find maximum frequency element
#include <stdio.h>
int main(){
    int i,j,n,ele,max=0;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++){
        int count=1;
        for (j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if (count>max){
            max=count;
            ele=arr[i];
        }
    }
    printf("Maximum frequency element=%d\n",ele);
    printf("Frequency=%d",max);
    return 0;
}    