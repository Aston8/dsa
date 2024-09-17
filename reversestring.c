#include<stdio.h>
#include<stdlib.h>

void main(){
    char s[100];
    gets(s);
    char temp;
    int len=0;
    while(s[len]!='\0'){
        len++;
    }
    printf("length of the string is %d",len);

    for(int i=0; i<(len-1)/2;i++){
        temp = s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;

    }

    printf("reversed string is %s",s);


}