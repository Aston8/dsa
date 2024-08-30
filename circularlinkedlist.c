#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


void traversal(struct Node *head){
    struct Node * ptr =head;
    
    do{
        printf("Element is :%d\n",ptr ->data);
        ptr =ptr->next;
    }while(ptr!=head);

};


struct Node *insertAtFirst(struct Node *head,int data){
    struct Node *ptr;
    ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr ->data =data;

    struct Node *p = head ->next;
    while(p ->next != head){//at this point ptr points last node
        p = p ->next;
    }

    p->next = ptr;
    ptr ->next=head;
    head =ptr;
    return(head);


};





int main(){
    struct Node *head, *first, *second, *third, *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 14;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 16;
    fourth->next = head;

    printf("Before insertion\n");
    traversal(head);

   
    head=insertAtFirst(head,54);
    printf("\nafter insertion\n");
    traversal(head);


    return 0;
}

