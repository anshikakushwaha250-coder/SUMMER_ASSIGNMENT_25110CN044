//Program to find common elements
#include <stdio.h>
int main(){
    int n1,n2,i,j;
    printf("Enter size of first array");
    scanf("%d",&n1);
    printf("Enter size of second array");
    scanf("%d",&n2);
    int arr1[n1],arr2[n2];
    printf("Enter elements of first array\n");
    for (i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter elements of second array\n");
    for (i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    for (i=0;i<n1;i++){
        for (j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                printf("%d ",arr1[i]);
                break;
            }
        }
    }
    return 0;
}    