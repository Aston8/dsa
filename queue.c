#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int r;
    int f;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r == q->size-1 ){
        return 1;
    }
        return 0;
    
}

int isempty(struct queue *q){
    if(q->f == q->r ){
        return 1;
    }
        return 0;
    
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("queue is full");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue *q){
    if(isempty(q)){
        printf("queue is empty");
        return -1;
    }else{
        int a;
        q->f++;
        a=q->arr[q->f];
        return a;
    }
}




int main(){
    struct queue q;
    q.size =10;
    q.r=-1;
    q.f=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    printf("\n%d",isempty(&q));    
    printf("\n%d",isFull(&q));
    printf("\nAfter operation\n");
   
    enqueue(&q,56);
    enqueue(&q,45);

    printf("%d dequeued element \n",dequeue(&q));
    
    printf("\n%d",isempty(&q));
    printf("\n%d",isFull(&q));

    return 0;
}