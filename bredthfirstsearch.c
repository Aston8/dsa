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

    //bfs code
    int node;
    int i=0;//starting node
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
                    {0,1,1,1,0,0,0},
                    {1,0,1,0,0,0,0},
                    {1,1,0,1,1,0,0},
                    {1,0,1,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0}
                };

    printf("%d\n",i);
    visited[i]=1;
    enqueue(&q,i);
    while (!isempty(&q))
    {
        node=dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j]==1 && visited[j]==0){//node coonected is true and visited is false
                printf("%d\n",j);
                visited[j]=1;
                enqueue(&q,j);
                
            }
        }
    }  
    return 0;
}