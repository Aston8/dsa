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


void preOrder(struct Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
        
    }
}
void InOrder(struct Node* root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
        
        
    }
}


int main(){
    //using function
    struct Node *p=createNode(4);
    struct Node *p1=createNode(1);
    struct Node *p2=createNode(6);
    struct Node *p3=createNode(5);
    struct Node *p4=createNode(2);
   
   
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    InOrder(p);
    
    return 0;
}