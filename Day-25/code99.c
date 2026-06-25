//Program to sort names alphabetically
#include <stdio.h>
#include <string.h>
int main(){
    int n,i,j;
    printf("Enter no. of names to enter");
    scanf("%d",&n);
    char name[n][50],temp[50];
    printf("Enter the names");
    for (i=0;i<n;i++){
        scanf("%s",name[i]);
    }
    //Buuble Sort
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(name[i],name[j])>0) {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }
    printf("Sorted names are:\n");
    for(i=0;i<n;i++){
        printf("%s\n",name[i]);
    }
    return 0;
}
        
    
    