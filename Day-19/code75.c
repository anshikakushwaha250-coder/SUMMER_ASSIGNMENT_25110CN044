//Program to transpose matrix
#include <stdio.h>
int main(){
    int row,col,i,j;
    printf("Enter no. of rows and columns of a matrix");
    scanf("%d %d",&row,&col);
    int arr1[row][col],arr2[col][row];
    printf("\nEnter the matrix");
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            arr2[j][i]=arr1[i][j];
        }
    }
    printf("The resultant transpose matrix is:\n");
    for (i=0;i<col;i++){
        for (j=0;j<row;j++){
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}

    