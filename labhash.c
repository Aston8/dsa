#include<stdio.h>
#include<stdlib.h>

#define m 10
int hashtable[m];

void intializehash(){
    for(int i=0;i<m;i++){
        hashtable[i]=-1;
    }
}

int hash(int key){
    return (key%m);
}

int hash1(int key,int i){
    return (key%m+i)%m;
}

void insert(){
    int key,index,i;
    printf("Enter the element to insert");
    scanf("%d",&key);
    index=hash(key);
    if(hashtable[index]==-1){
        hashtable[index]=key;
        printf("Element %d is inserted at index %d",key,index);
        return;
    }else{
        printf("collision element alreday exist in that index ");
        for( i=1;i<m;i++){
            index=hash1(key,i);
            if(hashtable[index]==-1){
                hashtable[index]=key;
                printf("Element %d is inserted at index %d",key,index);
                break;
            }
        }
        if(i==m){
            printf("cannot insert");
        }

    }
}

void display(){
    int i;
    printf("hash table");
    for(i=0;i<m;i++){
        printf("index%d\t value:%d\n",i,hashtable[i]);
    }
}


void main(){
    int choice;
    intializehash();
    do
    {
       printf("Enter 1 to insert 2 to display 3 to exit");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:insert();
            break;
       case 2:display();
            break;
       case 3:
            exit(0);
       default:
        break;
       }
    } while (choice!=3);
    
}