//Program to count words in a sntence
#include <stdio.h>
int main(){
    char str[200];
    int i,count=0;
    printf("Enter a string");
    gets(str);
    for (i=0;str[i]!='\0';i++) {
        if (str[i]!=' ' && (i==0 || str[i-1]==' ')){
            count++;
        }
    }
    printf("No. of words in string is %d",count);  
    return 0;
}
