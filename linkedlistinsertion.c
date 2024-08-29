#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traversel (struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d \n",ptr -> data);
        ptr =ptr ->next;
    }
}

struct Node * insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr;
    ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr ->data =data;

    ptr->next = head;
    return ptr;

};


struct Node * insertAtLast(struct Node *head,int data)
{
    struct Node *ptr;
    ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr ->data =data;


    struct Node *p =head;
    
    while(p->next != NULL){
        p=p->next;
        
    }
    
    p->next =ptr;
    ptr ->next = NULL;
    return head;

};


struct Node * insertAtIndex(struct Node *head,int data,int index)
{
    struct Node *ptr;
    ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr ->data =data;

    struct Node *p =head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
 
    
    ptr->next = p->next;
    p->next = ptr;
    return head;

};


struct Node * insertAtNode(struct Node *head,struct Node *prevnode, int data)
{
    struct Node *ptr;
    ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr ->data =data;

 
    
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;

};








int main(){
    struct Node *head,*first,*second,*third,*fourth;

    head =(struct Node *)malloc(sizeof(struct Node));
    first =(struct Node *)malloc(sizeof(struct Node));
    second =(struct Node *)malloc(sizeof(struct Node));
    third =(struct Node *)malloc(sizeof(struct Node));
    fourth =(struct Node *)malloc(sizeof(struct Node));

    head ->data= 7;
    head -> next =first;

    first ->data= 11;
    first -> next =second;

    second ->data= 14;
    second -> next =third;

    third ->data= 12;
    third -> next =fourth;

    fourth ->data= 16;
    fourth -> next =NULL;
 
    printf("before insertion\n");
    traversel(head);
    

    //head = insertAtFirst(head,56);
    head = insertAtIndex(head,56,1);
    //head = insertAtLast(head,56);
   // head = insertAtNode(head,second,56);
    printf("\nAfetr inserton\n");
    traversel(head);

    

    return (0);

}