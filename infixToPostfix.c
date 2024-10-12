#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stack{
    int size;
    int top;
    char *arr;
};

int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack *ptr,char val){
    if(isfull(ptr)){
        printf("stack overflow\n");
    }else
    ptr->top++;
    ptr->arr[ptr->top]=val;
}



char pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack underflow\n");
        return -1;
    }else{
   
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stacktop(struct stack *sp){
    return sp->arr[sp->top];
}


   
int precidence(char ch){
    if(ch == '*' || ch== '/')
        return 3;
    else if(ch == '+' || ch== '-')
        return 2;
    else
        return 0;
}   

int isoperator(char ch){
    if(ch == '+' || ch == '-' ||ch == '*' ||ch == '/')
        return 1;
    else
        return 0;
}


char *infixToPostfix(char *infix){
    struct stack *sp=(struct stack *)malloc(sizeof(struct  stack));
    
    
        sp->size=100;
        sp->top=-1;
        sp->arr=(char *)malloc(sp->size *sizeof(char));
        char *postfix =(char *)malloc((strlen(infix)+1) *sizeof(char));
        int i=0;
        int j=0;
        while(infix[i]!='\0')
        {
           if(!isoperator(infix[i])){
                postfix[j]=infix[i];
                i++,j++;
           }
           else{
                while(!isempty(sp) && precidence(infix[i]) <= precidence(stacktop(sp))){
                   postfix[j]=pop(sp);
                   j++;
                }
                push(sp,infix[i]);
                i++;
                
           }    
           
        }
        while(!isempty(sp)){
            postfix[j]=pop(sp);
            j++;
        }
        postfix[j]='\0';
        return postfix;
        
    
    


}



int main(){
    char * infix ="a-b+t/c";
    printf("postfix is %s",infixToPostfix(infix));
        
    return 0;
}