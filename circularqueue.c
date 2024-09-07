#include<stdio.h>
#include<stdlib.h>

struct circularqueue{
    int size;
    int r;
    int f;
    int *arr;
};

int isFull(struct circularqueue *q){
    if((q->r+1)%q->size == q->f ){
        return 1;
    }
        return 0;
    
}

int isempty(struct circularqueue *q){
    if(q->f == q->r ){
        return 1;
    }
        return 0;
    
}

void enqueue(struct circularqueue *q,int val){
    if(isFull(q)){
        printf("queue is full\n");
    }else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("enqueued element is %d\n",val);
    }
}

int dequeue(struct circularqueue *q){
    if(isempty(q)){
        printf("queue is empty\n");
    }else{
        int a;
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
        return a;
    }
}




int main(){
    int b ,c,d;
    struct circularqueue q;
    q.size =4;
    q.r=0;
    q.f=0;
    q.arr=(int *)malloc(q.size*sizeof(int));

    printf("\n%d",isempty(&q));    
    printf("\n%d",isFull(&q));
    printf("\nAfter enqueue\n");
   
    enqueue(&q,45);
    enqueue(&q,56);
    enqueue(&q,45); 
   
     printf("\n%d",isempty(&q));    
     printf("\n%d",isFull(&q));
     printf("\ndequeued element is %d\n",dequeue(&q));
     printf("dequeued element is %d\n",dequeue(&q));
     printf("dequeued element is %d\n",dequeue(&q));

    printf("\nAfter dequeue\n");    
    printf("\n%d",isempty(&q));
    printf("\n%d",isFull(&q));

    return 0;
}