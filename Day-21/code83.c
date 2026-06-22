//Program to count vowels and consonants
#include <stdio.h>
int main(){
    char str[50];
    int i,vowel=0,consonant=0;
    printf("Enter a string");
    gets(str);
    for (i=0;str[i]!='\0';i++){
        if (str[i]=='a'|| str[i]=='e'|| str[i]=='i'|| str[i]=='o'|| str[i]=='u'||str[i]=='A'|| str[i]=='E'|| str[i]=='I'|| str[i]=='O'|| str[i]=='U'){
            vowel++;
        }
        else if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            consonant++;
        }
    }
    printf("\nNo. of vowels=%d",vowel);
    printf("\nNo. of consonants=%d",consonant);
    return 0;
}