//Write a program to character frequency
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int freq[256] = {0};//ASCII has 256 characters
    int i;
    printf("Enter a string: ");
    gets(str);
    for (i = 0; str[i]!='\0'; i++) {
        freq[str[i]]++;
    }
    printf("\nCharacter frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i]> 0 && i!='\n') {
            printf("%c = %d\n",i,freq[i]);
        }
    }
    return 0;
}
