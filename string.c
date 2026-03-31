#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char returnString(char **str,int strsSize);
int main(){
    char * strarray[]={"Flower","Flow","Flight"};
    int size=sizeof(strarray)/sizeof(strarray[0]);
    printf("%d",size);
    // for(int i=0;i<)
    printf("%c",strarray[0][0]);
    return 0;
}