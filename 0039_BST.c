#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* left;
    struct node*right;
}node;

node* create_root(int data){
    node*root=(node*)malloc(sizeof(node));
    root->val=data;
    root->left=root->right=NULL;
    return root;
} 

node* insert(int data,node* root){
    if(!root) return create_root(data);
    if(data < root->val){
        root->left=insert(data,root->left);
    }
    else if(data > root->val) root->right=insert(data,root->right);
    return root;
}

void inorder(node*root){
    if(root){
        inorder(root->left);
        printf("%d  ",root->val);
        inorder(root->right);
    }
}

void postorder(node*root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->val);
    }
}

void preorder(node*root){
    if(root){
        printf("%d  ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

node* search(int key,node* root){
    if(!root || root->val==key) return root;
    else if(root->val > key) return search(key,root->left);
    else if(root->val < key) return search(key,root->right);
    return NULL;
}

node* min_node(node* root){
    if(!root) return NULL;
    else if(root->left) return min_node(root->left);
    return root;
}

node* delete_node(node* root,int data){
    if(!root) return NULL;
    else if(data > root->val){
        root->right=delete_node(root->right,data);
    }
    else if(data < root->val){
        root->left=delete_node(root->left,data);
    }
    else{
        if(!root->left && !root->right){//no child for data
            free(root);
            return NULL;
        }
        else if(!root->left || !root->right){//one child for data
            node*tmp;
            if(!root->left){ //no left child
                tmp=root->right;
            }
            else{
                tmp=root->left;
            }
            free(root);
            return tmp;
        }
        else { // two child for data
            node* ptr=min_node(root->right);
            root->val=ptr->val;
            root->right=delete_node(root->right,ptr->val);
        }
    }
    return root;
}

int main(){
    node*root=NULL;
    root=insert(12,root);
    root=insert(7,root);
    root=insert(6,root);
    root=insert(2,root);
    root=insert(10,root);
    root=insert(1,root);
    root=insert(4,root);
    root=delete_node(root,7);
    root=delete_node(root,10);
    printf("\nThe Inorder traversal way is: ");
    inorder(root);
    printf("\nThe Postorder Traversal way is: ");
    postorder(root);
    printf("\nThe Preorder Traversal way is: ");
    preorder(root);
    int data;
    printf("\nEnter key to search in the Binary Tree: ");
    scanf("%d",&data);
    node*key=search(data,root);
    if(key) printf("\nThe element %d is found\n",data);
    else printf("\nThe element %d is not found\n",data);
    root=delete_node(root,2);
    printf("The Inorder after deleting 2 is: ");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    preorder(root);
    key=search(2,root);
    if(key) printf("\nThe element %d is found\n",data);
    else printf("\nThe element %d is not found\n",data);
    return 0;
}