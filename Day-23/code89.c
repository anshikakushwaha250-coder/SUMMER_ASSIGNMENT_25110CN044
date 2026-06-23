//Program to find first non-repeating character
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        if (freq[str[i]]==1){
            printf("First non-repeating character: %c\n",str[i]);
            return 0;
        }
    }
    printf("No non-repeating character found");
    return 0;
}    