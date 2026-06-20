//Program to check symmetric matrix
#include <stdio.h>
int main() {
    int n,i,j,symmetric=1;
    printf("Enter the order of the matrix ");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter the matrix elements:\n");
    for (i=0;i<n;i++){
        for (j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (arr[i][j]!=arr[j][i]) {
                symmetric=0;
                break;
            }
        }
        if (symmetric==0) {
            break;
        }
    }
    printf("The matrix is \n");
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    if (symmetric)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}