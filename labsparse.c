#include<stdio.h>
#include<stdlib.h>
 struct Node{
    int row;
     int col;
     int data;
     struct Node * next;

 };

 struct Node *createNode(int row,int col,int val){
    struct Node * newNode=(struct Node *)  malloc(sizeof(struct Node));
    newNode->row=row;
    newNode->col=col;
    newNode->data=val;
    newNode->next =NULL; 
    return newNode;
}

struct Node *read(){
    int m,n,i,j;
    struct Node * start=NULL;
    struct Node * temp= NULL; 
    int a[100][100];
    printf("Enter the number of rows and columns");
    scanf("%d%d",&m,&n); 
    for ( i = 0; i < m ;i++)
    {
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
     for ( i = 0; i < m ;i++)
    {
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                struct Node *new =createNode(i,j,a[i][j]);
                if(start==NULL){
                    start=new;
                }else{
                    temp=start;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=new;
                    
                }
            }
        }
    }
    return start;
}


void display(struct Node *start){
    struct Node *temp = NULL;
    if(start==NULL){
        printf("empty");
        exit(0);
    }
    else{
        temp =start;
        printf("row:\tcolumn:\tvalue:\n");
        while(temp !=NULL){
            printf("%d\t%d\t%d",temp->row,temp->col,temp->data);
            temp=temp->next;
        }
    }
    
}

void transpose(struct Node *start){
    struct Node *temp = NULL;
    if(start==NULL){
        printf("empty");
        exit(0);
    }
    else{
        temp =start;
        while(temp!=NULL){
            int temp1 = temp->row;
            temp->row=temp->col;
            temp->col=temp1;
            temp=temp->next;
        }
    }
}
    
void main(){
    int ch;
    struct Node *start =NULL;
    do{
        printf("\nMENU:\n");
        printf(" 1.input sparse matrix\n 2.display matrix\n 3.transpose sparse matrix\n 4.exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:start=read();
                break;
            case 2:display(start);
                break;
            case 3:transpose(start);
                break;
            case 4:exit(0);
            default:printf("Invalid choice!!\n");
        }
    }while(ch!=4);
}