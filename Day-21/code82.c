//Program to reverse a string
#include <stdio.h>
int main(){
    char str[50],temp;
    int i,l=0;
    printf("Enter the string");
    gets(str);
    for (i=0;str[i]!='\0';i++){
        l++;
    }
    for (i=0;i<l/2;i++){
        temp=str[i];
        str[i]=str[l-1-i];
        str[l-1-i]=temp; 
    }
    printf("The reversed string is %s",str);
    return 0;
}