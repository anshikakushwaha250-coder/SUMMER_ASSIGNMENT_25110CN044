//Program to sort words by length
#include <stdio.h>
#include <string.h>
int main(){
    int n,i,j;
    printf("Enter no. of names to enter");
    scanf("%d",&n);
    char words[n][50],temp[50];
    printf("Enter the words");
    for (i=0;i<n;i++){
        scanf("%s",words[i]);
    }
    //Buuble Sort
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strlen(words[i])>strlen(words[j])){
                strcpy(temp,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],temp);
            }
        }
    }
    printf("Sorted words by length are:\n");
    for(i=0;i<n;i++){
        printf("%s\n",words[i]);
    }
    return 0;
}