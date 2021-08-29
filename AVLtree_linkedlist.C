#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int height;
    struct node*left;
    struct node*right;
}node;

int maximum(int a,int b){
    if(a>b) return a;
    return b;
}


int height(node* root){         // for isbalanced() function
    if(!root) return 0;
    return (1+maximum(height(root->left),height(root->right)));
}

int balance_factor(node* root){     // difference of height of left node and right node
    if(!root) return 0;
    int h1=0,h2=0;
    if(root->left) h1=root->left->height;
    if(root->right) h2=root->right->height;
    return (h1-h2);
}

int isbalanced(node* root){         // checks if tree is balanced
    if(!root) return 1;
    int heightdiff=height(root->left)-height(root->right);
    if((heightdiff>=-1 && heightdiff<=1) && isbalanced(root->left) && isbalanced(root->right)){
        return 1;
    }
    return 0;
}

node* rotate_right(node* a){    
    node* b=a->left;
    node* c=b->right;
    b->right=a;
    a->left=c;

    int h1=0,h2=0;
    if(a->left) h1=a->left->height;
    if(a->right) h2=a->right->height;
    a->height=1+maximum(h1,h2);
    
    if(b->left) h1=b->left->height;
    if(b->right) h2=b->right->height;
    b->height=1+maximum(h1,h2);
    return b;
}


node* rotate_left(node* a){
    node* b=a->right;
    node* c=b->left;

    b->left=a;
    a->right=c;

    int h1=0,h2=0;
    if(a->left) h1=a->left->height;
    if(a->right) h2=a->right->height;
    a->height=1+maximum(h1,h2);

    if(b->left) h1=b->left->height;
    if(b->right) h2=b->right->height;
    b->height=1+maximum(h1,h2);
    return b;
}

node* createnode(int data){
    node*root=(node*)malloc(sizeof(node));
    root->data=data;
    root->height=1;
    root->left=root->right=NULL;
    return root;
}

node* insert(int val,node*root){
    if(!root) return createnode(val);
    else if(root->data > val) root->left=insert(val,root->left);
    else if(root->data < val) root->right=insert(val,root->right);

    int h1=0,h2=0;
    if(root->left) h1=root->left->height;
    if(root->right) h2=root->right->height;
    root->height=1+maximum(h1,h2);

    int heightdiff=balance_factor(root);

    if(heightdiff>1 && val<root->left->data) return rotate_right(root);
    else if(heightdiff>1 && val>root->left->data){
        root->left=rotate_left(root->left);
        return rotate_right(root);
    }
    else if(heightdiff<-1 && val>root->right->data) return rotate_left(root);
    else if(heightdiff<-1 && val<root->right->data){
        root->right=rotate_right(root->right);
        return rotate_left(root);
    }
    return root;
}


node* min_node(node* root){     // return the immediate successor of given node
    if(!root) return NULL;
    else if(root->left) return min_node(root->left);
    return root;
}

node* delete_node(int val,node* root){
    if(!root) return root;
    else if(root->data > val) root->left=delete_node(val,root->left);
    else if(root->data < val) root->right=delete_node(val,root->right);
    else{
        node* tmp=NULL;
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(!root->left || !root->right){
            if(!root->left){
                tmp=root->right;
            }
            else tmp=root->left;
            free(root);
            return tmp;
        }
        else if(root->left!=NULL && root->right!=NULL){
            tmp=min_node(root->right);
            root->data=tmp->data;
            root->right=delete_node(root->data,root->right);
        }
    }

    if(!root) return NULL;

    int h1=0,h2=0;
    if(root->left) h1=root->left->height;
    if(root->right) h2=root->right->height;
    root->height=1+maximum(h1,h2);

    int heightdiff=balance_factor(root);

    if(heightdiff>1 && val<root->left->data) return rotate_right(root);
    else if(heightdiff>1 && val>root->left->data){
        root->left=rotate_left(root->left);
        return rotate_right(root);
    }
    else if(heightdiff<-1 && val>root->right->data) return rotate_left(root);
    else if(heightdiff<-1 && val<root->right->data){
        root->right=rotate_right(root->right);
        return rotate_left(root);
    }
    return root;
}   

void inorder(node*root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(node*root){
    if(!root) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    node*root=NULL;
    root = insert(14,root);
    root = insert(17,root);
    root = insert(11,root);
    root = insert(7,root);
    root = insert(53,root);
    root = insert(4,root);
    root = insert(13,root);
    root = insert(12,root);
    root = insert(8,root);
    root = insert(60,root);
    root = insert(19,root);
    root = insert(16,root);
    root = insert(20,root);
    printf("\nInorder traversal of AVL tree is: ");
    inorder(root);
    printf("\nPreorder traversal of AVL tree is: ");
    preorder(root);
    printf("\nPostorder traversal of AVL tree is: ");
    postorder(root);
    root = delete_node(8,root);
    root = delete_node(7,root);
    root = delete_node(11,root);
    root = delete_node(14,root);
    root = delete_node(17,root);
    printf("\nInorder traversal of AVL tree is: ");
    inorder(root);
    printf("\nPreorder traversal of AVL tree is: ");
    preorder(root);
    printf("\nPostorder traversal of AVL tree is: ");
    postorder(root);
    return 0;
}