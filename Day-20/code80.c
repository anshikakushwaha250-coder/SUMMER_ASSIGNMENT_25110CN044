//Program to find column-wise sum
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
    for (j=0;j<col;j++){
        sum=0;
        for (i=0;i<row;i++){
            sum=sum+arr[i][j];
        }
        printf("Sum of column %d=%d\n",j+1,sum);
    }
    return 0;
}