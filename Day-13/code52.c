//Program to count even and odd elements in an array
#include <stdio.h>
int main(){
    int a[100],n,i,even=0,odd=0;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Number of even elements=%d\n",even);
    printf("Number of odd elements=%d\n",odd);
    return 0;
}



