//Program to find longest word
#include <stdio.h>
int main() {
    char str[200],word[100],longest[100];
    int i=0,j=0,max=0,length=0;
    printf("Enter a string");
    gets(str);
    while (1){
        if (str[i]!=' ' && str[i]!='\0' && str[i]!='\n'){
            word[j++]=str[i];
        } 
        else{
            word[j]='\0';
            length=j;
            if (length>max){
                max=length;
                int k=0;
                for (k=0;k<j;k++){
                    longest[k]=word[k];
                }
                longest[k]='\0';
            }
            j=0;
        }
        if (str[i]=='\0')
            break;
        i++;
    }
    printf("Longest word: %s\n", longest);
    return 0;
}