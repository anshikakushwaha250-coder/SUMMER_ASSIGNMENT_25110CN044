//Program to check string rotation
#include <stdio.h>
#include <string.h>
int main() {
    char str1[100],str2[100],str3[200];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    if (strlen(str1)!=strlen(str2)) {
        printf("Not a rotation\n");
        return 0;
    }
    strcpy(str3,str1);//Copy str1 to str3
    strcat(str3,str1);//Concatenate str1 to str3
    
    if (strstr(str3,str2))//searches for str2 in str3
        printf("Rotation\n");
    else
        printf("Not a rotation\n");

    return 0;
}