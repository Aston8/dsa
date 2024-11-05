#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100], s[100], r[100],ans[100];
int i,j,k,m,c,flag; 
char *match();

int main(){
    printf("Enter the string");
    gets(str);
     //fgets(str,sizeof(str),stdin);

    printf("Enter the search String");
    // fgets(s,sizeof(s),stdin);
    gets(s);

    printf("Enter the replace string");
//    fgets(r,sizeof(r),stdin);
gets(r);
  

    match();

    printf("resultant string is %s",ans);

    return 0;
}
char *match(){
    i=j=m=c=k=0;
    flag=0;
    while(str[c]!= '\0'){
        if(str[m]==s[i]){
            m++;
            i++;
            if(s[i]=='\0'){
                for(k=0;r[k]!='\0';k++,j++){
                    ans[j]=r[k];
                }
                i=0;
                c=m;
                flag=1;
            }
        }else{
            ans[j]=str[c];
            j++;
            c++;
            i=0;
            m=c;
        }
    }
    ans[j]='\0';
    if(flag==0){
        printf("match not found");
    }
    return ans;
}