//Program to find first repeating character
#include <stdio.h>
#include <ctype.h>//for lowercase

int main() {
    char str[200];
    int freq[256] = {0};//ASCII has 256 characters
    int i;
    printf("Enter a string: ");
    gets(str);
    for (i=0;str[i]!='\0';i++) {
        str[i]=tolower(str[i]);
    }
    for (i = 0; str[i]!='\0'; i++) {
        freq[str[i]]++;
    }
    for (i=0;str[i]!='\0';i++){
        if (freq[str[i]]==2){
            printf("First repeating character: %c\n",str[i]);
            return 0;
        }
    }
    printf("No repeating character found\n");
    return 0;
}    