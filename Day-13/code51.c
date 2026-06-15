//Program to find largest and smallest element
#include <stdio.h>
int main(){
    int a[100],n,i,min,max;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    min=max=a[0];
    for(i=1;i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
        if (a[i]>max){
            max=a[i];
        }
    }
    printf("The largest and smallest elements are %d and %d",max,min);
    return 0;
}



