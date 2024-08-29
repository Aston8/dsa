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

struct Node * deleteFirst(struct Node *head)
{
    struct Node *ptr =head;
    head = head-> next;
    free(ptr);
    return(head);
};


struct Node * deleteLast(struct Node *head)
{
    
    struct Node *p = head;
    while(p->next->next != NULL){
        p=p->next;
        
    }
    struct Node *ptr = p->next;
    p->next = NULL;
    free(ptr);
    return head;

};


struct Node * deleteAtIndex(struct Node *head,int index)
{
    
    

    struct Node *p =head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
 
    struct Node *ptr=p->next;
    p->next = p->next->next;
    free(ptr);
    return head;
}

struct Node * deleteValue(struct Node *head,int value)
{
    
    

    struct Node *p =head;
    while(p->data !=value && p->next !=NULL){
        p=p->next;
    }
 

    if(p->data ==value){
    struct Node *ptr=p->next;
    p->next = p->next->next;
    free(ptr);
   }
    return head;

};


struct Node * deleteAtNode(struct Node *head,struct Node *prevnode)
{
    

 
    struct Node *ptr = prevnode->next;
    prevnode->next=prevnode->next->next;
    free(ptr);
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
 
    printf("before Deletion\n");
    traversel(head);
    

    //head = deleteFirst(head);
   // head =  deleteAtIndex(head,1);
    //head = deleteLast(head);
    //head = deleteAtNode(head,second);
    head=deleteValue(head,14);
    printf("\nAfetr Deletion\n");
    traversel(head);

    

    return (0);

}