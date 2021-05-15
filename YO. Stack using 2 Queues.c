#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

node* f1=NULL;
node* r1=NULL;
node* f2=NULL;
node* r2=NULL;

void push1(int data){
    node *new=malloc(sizeof(node));
    new->data=data;
    new->link=NULL;
    if(f1==r1 && f1==NULL){
        f1=(node*)malloc(sizeof(node));
        r1=(node*)malloc(sizeof(node));
        f1=r1=new;
    }
    else if(f1==r1){
        f1->link=new;
        r1=new;
        //r1->link=NULL;
    }
    else{
        r1->link=new;
        r1=r1->link;
        //r1->link=NULL;
    }
}

void push2(int data){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->link=NULL;
    if(f2==r2 && f2==NULL){
        f2=(node*)malloc(sizeof(node));
        r2=(node*)malloc(sizeof(node));
        f2=new,r2=new;
    }
    else if(f2==r2){
        f2->link=new;
        r2=new;
        //r1->link=NULL;
    }
    else{
        r2->link=new;
        r2=r2->link;
        //r1->link=NULL;
    }
}

int pop1(){
	int a=0;
    node*ptr=f1;
    if(f1==r1 && f1==NULL){
    printf("The queue1 is empty\n");
    return -1;
    }
    else if(f1==r1){
    	a=f1->data;
        f1=r1=NULL;
        free(ptr);
    }
    else{
    	a=f1->data;
        f1=f1->link;
        free(ptr);
    }
    return a;
}

int pop2(){
    int a;
    node*ptr=f2;
    if(f2==r2 && f2==NULL){
    printf("The queue2 is empty\n");
	return -1;
	}
    else if(f2==r2){
    	a=f2->data;
        f2=r2=NULL;
        free(ptr);
    }
    else{
    	a=f2->data;
        f2=f2->link;
        free(ptr);
    }
    return a;
}

void print(){
    printf("The stack is: \n");
    node* ptr=f1;
    while(ptr!=NULL){
        printf("\t%d\n",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("Enter  1-->push to stack\n");
        printf("       2-->pop from stack\n");
        printf("      any-->exit program\n");
        printf("Enter ur choice: ");
        scanf("%d",&choice);
        if(choice==1){
            int data;
            printf("\nEnter data: ");
            scanf("%d",&data);
            push2(data);
            if(f1==r1 && f1==NULL) push1(pop2());
            else{
                while(f1!=NULL){
                    push2(pop1());
                }
                while(f2!=NULL) push1(pop2());
            }
        }
        else if(choice==2){
        int p=pop1();
        if(p!=-1) printf("\nThe element %d is deleted\n",p);
        else printf("\nThe element is not deleted\n");
        }
        else break;
        print();
    }
}
