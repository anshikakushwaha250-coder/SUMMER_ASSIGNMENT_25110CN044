//Program to print character pyramid
#include <stdio.h>
int main(){
    int i,j,n,space;
    printf("Enter no. of rows");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for (space=1;space<=n-i;space++){
            printf(" ");
        }
        for (j=1;j<=i;j++){
            printf("%c",j+64);
        }
        for (j=i-1;j>=1;j--){
            printf("%c",j+64);
        }
        printf("\n");
    }
    return 0;
}