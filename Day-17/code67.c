//Program to intersection of arrays
#include <stdio.h>
int main(){
    int n1,n2,i,j,k=0;
    printf("Enter size of first array");
    scanf("%d",&n1);
    printf("Enter size of second array");
    scanf("%d",&n2);
    int arr1[n1],arr2[n2],arr3[n1];
    printf("Enter elements of first array\n");
    for (i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter elements of second array\n");
    for (i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    for (i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                arr3[k++]=arr1[i];
                break;
            }
        }
    }
    printf("Intersection array\n");
    for(i=0;i<k;i++){
        printf("%d\t",arr3[i]);
    }
    return 0;
}    