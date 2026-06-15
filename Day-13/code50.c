//Program to find sum and average of an array
#include <stdio.h>
int main(){
    int a[100],n,i,sum=0;
    float avg;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    printf("The sum of array elements is %d\n",sum);
    avg=(float)sum/n;
    printf("The average of array elements is %.2f\n",avg);
    return 0;
}



