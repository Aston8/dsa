#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * right;
    struct Node *left;
};
 
struct Node *createNode(int data){
    struct Node *newNode= (struct Node *)malloc(sizeof(struct Node));
    newNode->data =data;//
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root,int data){
    if(root==NULL)
       return createNode(data);
    if(data<root->data){
        root->left= insertNode(root->left,data);//
    }else if(data>root->data){
       root->right=insertNode(root->right,data);//
    }
    return root;
}

void postOrder(struct Node * root){//
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d",root->data);
    }
}
void  preOrder(struct Node * root){//
    if(root!=NULL){
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node * root){//
    if(root!=NULL){
        inOrder(root->left);
        printf("%d",root->data);
        inOrder(root->right);
    }
}

struct Node * search(struct Node *root,int key){
    if(root == NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    return search(root->right,key);
}


int main(){
    struct Node *root=NULL;
    int choice,data,n,key;
    do{
        printf("1 insert \n 2.post \n3.pre \n4 inorder \n5 seratch \n6 exit");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("enter the number of elements");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    scanf("%d",&data);
                    root =insertNode(root,data);//
                }
            break;
            case 2:printf("post");
                postOrder(root);//
                break;
            case 3:printf("pre");
                preOrder(root);
                break;
            case 4:printf("in");
                inOrder(root);
                break;
            case 5:printf("Enter the serch");
                scanf("%d",&key);
                struct Node *result = search(root,key);
                if(result!=NULL){
                    printf("the element %d is fount",key);
                }else{
                    printf("the element %d is not fount",key);
                }
                break;
            case 6:
                exit(0);

        default:
            break;
        }
    }while(choice !=6);
    


    return 0;
}