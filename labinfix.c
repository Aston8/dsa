#include<stdio.H>
#include<stdlib.h>
#include<ctype.h>

#define size 50

char s[size];
int top=-1;
int cp=0,co=0;//

void push(char elem){
    s[++top]=elem;
}

char pop(){
    return (s[top--]);
}

int pr(char elem){
    switch (elem)
    {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':return 4;
        default:-1;
    }
}

void main(){
    char infix[50],posf[50],elem,ch;
    int i=0;
    int k=0,prec;
    printf("Enter the infix expression");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0'){//
        if(ch=='('){
            push(ch);
        }
        else if(isalnum(ch)){
            posf[k++]=ch;
            co++;

        }
        else if(ch==')'){
            while(s[top]!='(')//
                posf[k++]=pop();
            elem =pop();
            
        }else{
            cp++;
            prec=pr(ch);
            if(prec == -1){
                printf("invalid operator");
                exit(1);
            }
            while(pr(s[top])>=prec)//
                posf[k++]=pop();
            push(ch);
            
        }
    }

    while(s[top]!='#'){
        if(s[top]=='('){
            printf("mismathed parac");
            exit(0);
        }else if(cp!=co-1){//
            printf("invalid Expression");
            exit(0);
        }else{
            posf[k++]=pop();
        }
    }
    posf[k]='\0';
    printf("postfix expression is %s",posf);

}