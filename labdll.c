#include<stdio.h>
#include<stdlib.h>

struct Node{
    int usn;
    char name[30];
    char branch[30];
    int sem;
    long phone;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(){
    struct Node * newNode = (struct Node *)malloc (sizeof(struct Node));
    printf("enter usn name branch sem phone\n");
    scanf("%d%s%s%d%ld",&newNode->usn,newNode->name,newNode->branch,&newNode->sem,&newNode->phone);
    newNode->next =NULL;
    newNode->prev = NULL;
    return newNode;
}
struct Node * insertFirst(struct Node *head){
    struct Node *newNode = createNode();
    if(head!=NULL){
        newNode->next =head;
        head->prev=newNode;
    }
    head=newNode;
    return head;

}
struct Node * insertlast(struct Node *head){
    struct Node *newNode = createNode();
    struct Node *temp=head;
    if(head==NULL){
      return newNode;
    }else{
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev=temp;
    }
       return head;

}
struct Node * deletefirst(struct Node *head){
    struct Node *temp;
    if(head==NULL){
        printf("List is empty");
        return NULL;
    }else if(head-> next ==NULL){
        free(head);
        return NULL;
    }else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    return head;
}
struct Node * deletelast(struct Node *head){
   if(head==NULL){
        printf("List is empty");
        return NULL;
    }else if(head-> next ==NULL){
        free(head);
        return NULL;
    }else{
        struct Node *temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    return head;
}
void display(struct Node * head){
    int count =0;
    struct Node *temp = head;
    if(head==NULL){
        printf("list is empty\n");
    }
    printf("usn\tname\tbranch\tsem\tphone\n");
    while(temp!=NULL){
        printf("%d \t%s\t %s \t%d \t%ld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phone);
        temp=temp->next;
        count ++;
    }
    printf("total no of students%d\n",count);
}


int main(){
    struct Node *head = NULL;
    int choice;
    do{
        printf("menu");
        printf("Enter 1 for display\n 2 for insert at first \n3 for insert at last\n 4 for delete at first \n5 for delete at last \n 6 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            head=insertFirst(head);
            break;
        case 3:
            head=insertlast(head);
            break;
        case 4: 
            head=deletefirst(head);
            break;
        case 5: 
            head=deletelast(head);
            break;
        case 6:
            exit(0);
        
        default:
            break;
             
        }
    }while(choice!=6);
    


    return 0;
}