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

//gives data in ascending order for BST

void InOrder(struct Node* root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
        
        
    }
}

//checking if it is BST or not
int isBST(struct Node* root){
    static struct Node* prev=NULL;
    if(root!=NULL){
        
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;//if root is null we are assuming it as BST
    }

}


//searching for a value in BST
struct Node *search(struct Node * root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data < key){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}



//iterative search for BST
struct Node *iterativesearch(struct Node * root,int key){
    while (root!=NULL)
    {
       if(root->data==key){
           return root;
       }
       else if(root->data<key){
           root=root->right;
       }
       else{
           root=root->left;
       }
    }
    return NULL;
    
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

    InOrder(p);//gives data in ascending order for BST
    printf("\n");
    printf("%d",isBST(p));//checking if it is BST or not
    printf("\n");


     
     //searching for a value in BST
    struct Node *n= search(p,1);
    if (n != NULL)
    {
        printf("found %d\n",n->data);
    }
    else{
        printf("element not found\n");
    }
    

    //iterative search for BST
    struct Node *a= iterativesearch(p,1);
    if (a != NULL)
    {
        printf("found %d\n",a->data);
    }
    else{
        printf("element not found\n");
    }
   
    return 0;


}