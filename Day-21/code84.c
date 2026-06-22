//Program to convert lowercase into uppercase
#include <stdio.h>
int main(){
    char str[50];
    int i;
    printf("Enter a string");
    gets(str);
    for (i=0;str[i]!='\0';i++) {
        if (str[i]>='a' && str[i]<='z') {
            str[i]=str[i]-32; //'a'(97)-'A'(65)=32
        }
    }
    printf("Uppercase string is %s", str);
    return 0;
}