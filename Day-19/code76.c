//Program to find diagonal sum
#include <stdio.h>
int main(){
    int row,col,i,j,s1=0,s2=0;
    printf("Enter no. of rows and columns of a matrix");
    scanf("%d %d",&row,&col);
    int a[row][col];
    if (row==col){
        printf("\nEnter the matrix");
        for (i=0;i<row;i++){
            for (j=0;j<col;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for (i=0;i<row;i++){
            s1=s1+a[i][i];
            s2=s2+a[i][row-1-i];
        }
        printf("The sum of main diagonal elements=%d",s1);
        printf("\nThe sum of off diagonal elements=%d",s2);
    }    
    else{
        printf("Sum of diagonals can not be generated");
    }
    return 0;
}        