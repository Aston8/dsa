#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


void traverse(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}



struct Node* deleteFirst(struct Node *head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}



struct Node* deleteLast(struct Node *head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    if (head->next == NULL) { // If there's only one element
        free(head);
        return NULL;
    }


    struct Node *p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    struct Node *ptr = p->next;
    p->next = NULL;
    free(ptr);
    return head;
}




struct Node* deleteAtIndex(struct Node *head, int index) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    if (index == 0) {
        return deleteFirst(head);
    }

    struct Node *p = head;
    int i = 0;
    while ( i != index - 1) {
        p = p->next;
        i++;
    }
    
    struct Node *ptr = p->next;
    p->next = p->next->next;
    free(ptr);
    return head;
}



struct Node* deleteValue(struct Node *head, int value) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }


    if (head->data == value) {
        return deleteFirst(head);
    }


    struct Node *p = head;
    struct Node *prev = NULL;
    while (p != NULL && p->data != value) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Value not found in the list.\n");
        return head;
    }
    
    prev->next = p->next;
    free(p);
    return head;
}

struct Node* deleteAtNode(struct Node *head, struct Node *prevnode) {
    if (head == NULL || prevnode == NULL || prevnode->next == NULL) {
        printf("Invalid operation. Check if the list is empty or the provided node is valid.\n");
        return head;
    }
    struct Node *ptr = prevnode->next;
    prevnode->next = prevnode->next->next;
    free(ptr);
    return head;
}

int main() {
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
    fourth->next = NULL;

    printf("Before Deletion\n");
    traverse(head);

    // Uncomment one of the following lines to test different deletion functions
    // head = deleteFirst(head);
    // head = deleteAtIndex(head, 1);
    // head = deleteLast(head);
    // head = deleteAtNode(head, second);
    head = deleteValue(head, 14);

    printf("\nAfter Deletion\n");
    traverse(head);

    return 0;
}
