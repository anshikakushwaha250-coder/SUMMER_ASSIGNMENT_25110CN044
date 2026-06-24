//Program to remove duplicate characters
#include <stdio.h>
int main() {
    char str[100],new[100];
    int i,j,k=0,flag=0;
    printf("Enter a string");
    scanf("%s",str);
    for (i=0;str[i]!='\0';i++){
        flag=0;
        for (j=0;j<k;j++){
            if (str[i]==new[j]) {
                flag=1;
                break;
            }
        }
        if (flag==0) {
            new[k++]=str[i];
        }
    }
    new[k]='\0';
    printf("After removing duplicates: %s\n",new);
    return 0;
}