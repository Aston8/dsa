#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};


void startfromfirst(struct Node *ptr){
    while(ptr != NULL){
        printf("Element is:%d\n",ptr->data);
        ptr=ptr->next;
    }

}


void startfromlast(struct Node *ptr){

    while(ptr->next != NULL){
        ptr=ptr->next;
    }

    while(ptr != NULL){
        printf("Element is:%d\n",ptr->data);
        ptr=ptr->prev;
    }

}





int main(){
    struct Node *n1,*n2,*n3,*n4;

    n1 =(struct Node *)malloc(sizeof(struct Node));
    n2 =(struct Node *)malloc(sizeof(struct Node));
    n3=(struct Node *)malloc(sizeof(struct Node));
    n4 =(struct Node *)malloc(sizeof(struct Node));
    

    n1 ->data= 7;
    n2 ->data= 9;
    n3 ->data= 12;
    n4 ->data= 13;

   n1->next=n2;
   n1->prev=NULL;

   n2->next=n3;
   n2->prev=n1;

   n3->next=n4;
   n3->prev=n2;

   n4->next=NULL;
   n4->prev=n3;


    startfromfirst(n1);
    
    startfromlast(n1);
return (0);

} 