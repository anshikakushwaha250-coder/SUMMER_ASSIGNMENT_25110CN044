//Program to display and input an array
#include <stdio.h>
int main(){
    int a[100],n,i;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array elements are:\n");
    for (i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}



