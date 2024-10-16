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


struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if(data==root->data){
        printf("cannot enter same value in BST\n");
        return;
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}



int main(){
    //using function
    struct Node *p=createNode(5);
    struct Node *p1=createNode(3);
    struct Node *p2=createNode(6);
    struct Node *p3=createNode(1);
    struct Node *p4=createNode(4);
   
   
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insertNode(p, 6);
    printf("%d", p->right->right->data);

   
    return 0;


}