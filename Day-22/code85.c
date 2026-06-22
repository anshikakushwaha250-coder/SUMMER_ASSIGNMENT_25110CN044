//Program to check palindrome string
#include <stdio.h>
#include <ctype.h>
int main(){
    char str[50];
    int i,l=0,flag=1;
    printf("Enter the string");
    gets(str);
    for (i=0;str[i]!='\0';i++){
        l++;
    }
    //Converting to lowercase
    for (i=0;i<l;i++) {
        str[i]=tolower(str[i]);
    }
    for (i=0;i<l/2;i++){
        if(str[i]!=str[l-i-1]){
            flag=0;
            break;
        }
    }
    if(flag==1)
        printf("%s is palindrome\n",str);
    else
        printf("%s is not palindrome\n",str);    
    return 0;
}