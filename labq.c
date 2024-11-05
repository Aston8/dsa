#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Q[MAX];
int front = -1;
int rear = -1;

void insert(){
    int num;
    printf("Enter the number top be inserted");
    scanf("%d",&num);
    if(( front == 0 && rear == MAX-1) || (rear == front -1)){
        printf("overflow");
    }else if(front ==-1 && rear ==-1){
        front =0;
        rear=0;
        Q[rear]=num;
    }else if(rear== MAX-1 && front !=0){
        rear=0;
        Q[rear]=num;
    }else{
        rear++;
        Q[rear]=num;
    }
}
int delete(){
    if(front ==-1 && rear ==-1){
        printf("underflow");
        return -1;
    }
    int val=Q[front];
    if(front ==0 && rear == 0){
        front ==-1;
        rear== -1;
    }else {
        if(front ==MAX-1){//
            front =0;
        }else{
            front++;
        }
    }
    return val;
}
void display(){
    int i;
     if(front ==-1 && rear ==-1){
        printf("underflow");
        return ;//
    }else{
        if(front<rear){
            for(i=front;i<=rear;i++)//
                printf("%d",i);
        }else{
            for(i=front;i<MAX;i++)//
                printf("%d",i);
            for(i=0;i<=rear;i++)//
                printf("%d",i);
        }
    }
    
}
int main(){
    int choice,n,val;
    do
    {
       printf("Enter 1 to insert \n 2.delete\n 3 display\n 4 to exit");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
           insert();
            break;
       case 2:
          val=delete();
        if(val != -1){
            printf("delted elment is %d",val);
        }
        case 3:
            display();
            break;
        case 4:
            exit(0);
       default:
        break;
       }
    } while (choice!=4);
    
    

    return 0;
}
