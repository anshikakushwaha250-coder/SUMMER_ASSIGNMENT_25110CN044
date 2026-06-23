//Program to find maximum occuring character
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    int freq[256]={0};
    int i;
    int max = 0;
    char result;

    printf("Enter a string: ");
    gets(str);
    
    for (i=0;str[i]!='\0';i++) {
        str[i]=tolower(str[i]);
    }

    for (i=0;str[i]!='\0';i++) {
        freq[str[i]]++;
    }
    for (i=0;i<256;i++) {
        if (freq[i]>max) {
            max=freq[i];
            result=(char)i;
        }
    }
    printf("Maximum occurring character: %c\n",result);
    printf("Frequency: %d\n",max);
    return 0;
}