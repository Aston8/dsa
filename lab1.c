#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct Node{
    int sem;
    long int phno;
    char name[20],branch[5],usn[10];
    struct Node *next;
}*first=NULL,*last=NULL,*temp=NULL,*temp1=NULL;

void create(){
    temp=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter usn, name,branch,sem,phone no\n");
    scanf("%s%s%s%d%ld",&temp->usn,&temp->name,&temp->branch,&temp->sem,&temp->phno);
    temp->next=NULL;
    count++;
}

void insert_Front(){
    if(first==NULL){
        create();
        first=temp;
        last=first;

    }
    else{
        create();
        temp->next=first;
        first=temp;
    }
    printf("\n Successfully inserted node at the front\n");
}

void insert_End(){
    if(first==NULL){
        create();
        first=temp;
        last=first;
    }
    else{
        create();
        last->next=temp;
        last=temp;
    }
    printf("\n Successfully inserted node at the end\n");
}

void display(){
    if(first==NULL){
        printf("List Empty\n");
        return;
    }
    printf("\n List contents are\n");
    temp=first;
    printf("\nUSN\tName\tBranch\tSem\tPhone Number\n");
    printf("********************************************\n");
    while(temp!=NULL){
        printf("%s\t%s\t%s\t%d\t%ld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
        temp=temp->next;
    }
    printf("\n Number of students=%d\n",count);
}

void delete_End(){
    struct Node *temp;
    if(first==NULL){
        printf("List is Empty\n");
        return;
    }
    printf("\n Deleted node information is ");
    temp=first;

    if(temp->next==NULL){
        printf("%s\t%s\t%s\t%d\t%ld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
        free(temp);
        first=NULL;
    }
    else{
        while(temp->next!=last)
        temp=temp->next;
        printf("%s\t%s\t%s\t%d\t%ld\n",last->usn,last->name,last->branch,last->sem,last->phno);
        free(last);
        temp->next=NULL;
        last=temp;
    }
    count--;
}

void delete_Front(){
    struct Node *temp;
    if(first==NULL){
        printf("List is Empty\n");
        return;
    }
    printf("\n Deleted node information is ");
    temp=first;

    if(temp->next==NULL){
        printf("%s\t%s\t%s\t%d\t%ld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
        free(temp);
        first=NULL;
    }
    else{
        first=temp->next;
        printf("%s\t%s\t%s\t%d\t%ld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
        free(temp);
    }
    count--;
}

void stack(){
    int ch;
    printf("\n1.Push\n2.Pop\n3.Display\n4.Enter your choice\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 : insert_Front();
                break;
        case 2 : delete_Front();
                break;
        case 3 : printf("Stack contents are\n");
                 display();
                break;
    }
}

void main(){
    int ch,n,i;
    printf("---------------MENU---------------");
    printf("\n1 - Create Single Linked list");
    printf("\n2 - Status of SLL");
    printf("\n3 - Insertion at End");
    printf("\n4 - Deletion at End");
    printf("\n5 - Insertion at Front");
    printf("\n6 - Deletion at Front");
    printf("\n7 - Demonstration of Stack");
    printf("\n8 - Exit\n");
    printf("-------------------------------------------\n");

    do{
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("Enter number of students\n");
                     scanf("%d",&n);
                     for(i=0;i<n;i++)
                     insert_Front();

            case 2 : display();
                     break;
                
            case 3 : insert_End();
                     break;

            case 4 : delete_End();
                     break;

            case 5 : insert_Front();
                     break;

            case 6 : delete_Front();
                     break;

            case 7 : stack();
                     break;
            
            case 8 : exit(0);
            default: printf("Invalid option");

        }
    }while(ch!=8);
}