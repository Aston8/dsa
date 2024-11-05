#include<stdio.h>
#include<stdlib.h>
 struct Node
 {
    int usn;
    char name[30];
    char branch[30];
    int sem;
    long phone;
    struct Node *next;
 };
 

 struct Node *createnode(){
    struct Node *new_node= (struct  Node *) malloc(sizeof(struct Node));
    printf("Enter  usn name branch sem phone");   
    scanf("%d %s %s %d %ld",&new_node->usn,new_node->name,new_node->branch,&new_node->sem,&new_node->phone) ;
    new_node ->next = NULL;
    return new_node ;
 }

 struct Node * insertFirst(struct Node *head){
    struct Node *new_node = createnode();
    if(head != NULL){
        new_node->next =head;
    }
    head = new_node;
    return head;
 }
 

 struct Node * insertAtlast(struct Node *head){
    struct Node *new_node = createnode();
    struct Node * temp = head;
    if(head == NULL){
       return new_node;
    }else{

    while(temp->next != NULL){
            temp=temp->next;
        }
    temp->next = new_node;
    return head;
    }
 }

struct Node * deletefirst(struct Node *head){
     struct Node * temp;
    if(head == NULL){
        printf("list is empty");
        return NULL;
    }
    else if(head ->next == NULL){
        free(head);
        return NULL;
    }else{
        temp=head;
        head = head ->next;
        free(temp);
        
    }
    return head;
 }


 struct Node * deleteLast(struct Node *head){
    struct Node * temp = head;
    if(head == NULL){
        printf("list is empty");
        return NULL;
    }
     else if(head ->next == NULL){
        free(head);
        return NULL;
    }else{
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    
    }
    return head;
 }


void display(struct Node *head){
    int count =0;
    struct Node * temp = head;
    if(temp==NULL){
        printf("No data");
        return;
    }
     printf("usn\t name\t branch\t sem \t phone");
     while(temp!= NULL){
       printf("%d \t%s\t %s \t%d \t%d\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phone) ;
       temp=temp->next;
       count ++;
    }
    printf("total number of stuidents %d",count);
}

int main(){
     struct Node *head = NULL;
    int choice, i, n;
    
    do {
        printf("\nMenu:\n");
        printf("1. Insert multiple students at first\n");
        printf("2. Display list\n");
        printf("3. Insert at first\n");
        printf("4. Delete from first\n");
        printf("5. Insert at last\n");
        printf("6. Delete from last\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("How many students? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    head = insertFirst(head);
                }
                break;
                
            case 2:
                display(head);
                break;
                
            case 3:
                head = insertFirst(head);
                break;
                
            case 4:
                head = deletefirst(head);
                break;
                
            case 5:
                head = insertAtlast(head);
                break;
                
            case 6:
                head = deleteLast(head);
                break;
                
            case 7:
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }while(choice !=7);
    return 0;
}
  
