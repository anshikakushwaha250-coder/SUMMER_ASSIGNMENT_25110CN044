//Program to find row-wise sum
#include <stdio.h>
int main(){
    int i,j,row,col,sum;
    printf("Enter no. of rows and columns of a matrix");
    scanf("%d %d",&row,&col);
    int arr[row][col];
    printf("Enter matrix elements\n");
    for (i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("The matrix is:\n");
    for (i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<row;i++){
        sum=0;
        for (j=0;j<col;j++){
            sum=sum+arr[i][j];
        }
        printf("Sum of row %d=%d\n",i+1,sum);
    }
    return 0;
}