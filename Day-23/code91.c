//Program to check anagram strings
//An anagram means two strings contain the same characters with the same frequencies, possibly in a different order.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char str1[100], str2[100];
    int freq[256] = {0};
    int i;

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    for (i = 0; str1[i] != '\0'; i++)
        str1[i] = tolower(str1[i]);
    for (i = 0; str2[i] != '\0'; i++)
        str2[i] = tolower(str2[i]);

    if (strlen(str1) != strlen(str2)) {
        printf("Strings are not anagrams\n");
        return 0;
    }

    // Count characters of strings
    for (i = 0; str1[i]!='\0';i++)
        freq[str1[i]]++;

    for (i = 0; str2[i]!='\0';i++)
        freq[str2[i]]--;

    // All frequencies should be zero
    for (i=0;i<256;i++){
        if (freq[i]!=0){
            printf("Strings are not anagrams\n");
            return 0;
        }
    }
    printf("Strings are anagrams\n");
    return 0;
}