//Program to write function for fibonacci
#include <stdio.h>
void fibonacci(int);
int main(){
    int n;
    printf("Enter no. of terms");
    scanf("%d",&n);
    fibonacci(n);
    return 0;

}
void fibonacci(int n){
    int i,next,a=0,b=1;
    for (i=1;i<=n;i++){
        printf("%d ",a);
        next=a+b;
        a=b;
        b=next;
    }
}