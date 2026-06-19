//Program to add matrices
#include <stdio.h>
int main(){
    int row,col,i,j;
    printf("Enter no. of rows and columns of a matrix");
    scanf("%d %d",&row,&col);
    int arr1[row][col],arr2[row][col],arr3[row][col];
    printf("\nEnter first matrix");
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\nEnter second matrix");
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            arr3[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    printf("\n The resultant addition matrix is:\n");
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            printf("%d\t",arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}