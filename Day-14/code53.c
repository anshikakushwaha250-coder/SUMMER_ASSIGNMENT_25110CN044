//Program to Linear Search
#include <stdio.h>
int main(){
    int a[100],x,n,i,flag=0;
    printf("Enter no. of elements");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter elements to be searched");
    scanf("%d",&x);
    for (i=0;i<n;i++){
        if(a[i]==x){
            flag=1;
            break;
        }
    }
    if (flag==1){
        printf("Element found at %dth position",i+1);
    }
    else{
        printf("Unsuccessful search");
    }
    return 0;
}