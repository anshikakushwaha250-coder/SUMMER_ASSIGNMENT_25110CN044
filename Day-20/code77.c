//Program to multiply matrices
#include <stdio.h>
int main(){
    int r1,c1,r2,c2,i,j,k;
    printf("Enter no. of rows and columns of a matrix 1");
    scanf("%d %d",&r1,&c1);
    printf("Enter no. of rows and columns of a matrix 2");
    scanf("%d %d",&r2,&c2);

    int arr1[r1][c1],arr2[r2][c2],arr3[r1][c2];
    printf("\nEnter first matrix");
    for (i=0;i<r1;i++){
        for (j=0;j<c1;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\nEnter second matrix");
    for (i=0;i<r2;i++){
        for (j=0;j<c2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    if (c1==r2){
        for (i=0;i<r1;i++){
            for (j=0;j<c2;j++){
                arr3[i][j]=0;
                for(k=0;k<c1;k++){
                    arr3[i][j]=arr3[i][j]+arr1[i][k]*arr2[k][j];
                }
            }
        }
        printf("\nMatrix 1:\n");
            for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){
                    printf("%d ", arr1[i][j]);
                }
            printf("\n");
        }
        printf("\nMatrix 2:\n");
            for(i=0;i<r2;i++){
                for(j=0;j<c2;j++){
                    printf("%d ", arr2[i][j]);
                }
            printf("\n");
        }



        printf("The resultant matrix is:\n");
        for (i=0;i<r1;i++){
            for (j=0;j<c2;j++){
                printf("%d  ",arr3[i][j]);
            }
        printf("\n");
        }
    }
    else{
        printf("Multiplication is not possible!");
    }     
    return 0;
}