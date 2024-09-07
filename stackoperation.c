#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
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

void push(struct stack *ptr,int val){
    if(isfull(ptr)){
        printf("stack overflow\n");
    }else
    ptr->top++;
    ptr->arr[ptr->top]=val;

}

int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack underflow\n");
        return -1;
    }else{
   
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}



int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size *sizeof(int));

    

    

    printf("%d",isempty(s));
    printf("\n%d",isfull(s));

    printf("\nAfter operation");
    push(s,56);
    push(s,46);
    
    printf("\n%d",isempty(s));
    printf("\n%d",isfull(s));

    printf("\npoped value%d",pop(s));

 return 0;   
}