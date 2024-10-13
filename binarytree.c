#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *n;//creating a node pointer
    n=(struct Node *)malloc(sizeof(struct Node));
    n->data = data;//setting the data
    n->left = NULL;//setting the left and right children to NULL
    n->right = NULL;//setting the left and right children to NULL
    return n;//finally returning the created node
}




int main(){
    //using function
    struct Node *p=createNode(2);
    struct Node *p1=createNode(1);
    struct Node *p2=createNode(4);
   
   
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;




   // // Constructing the root node
    // struct Node *p;
    // p = (struct Node *) malloc(sizeof(struct Node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;

    // // Constructing the second node
    // struct Node *p1;
    // p1 = (struct Node *) malloc(sizeof(struct Node));
    // p->data = 1;
    // p1->left = NULL;
    // p1->right = NULL;

    // // Constructing the third node
    // struct Node *p2;
    // p2 = (struct node *) malloc(sizeof(struct Node));
    // p->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;

     // Linking the root node with left and right children
    // p->left = p1;
    // p->right = p2;
    
   

    return 0;
}