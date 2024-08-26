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

    fourth ->data= 12;
    fourth -> next =NULL;

    traversel(head);


    return (0);

}