#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

void insert(int data){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    if(rear==NULL){
        front =rear=new;
        rear->link=front;
    }
    else{
        rear->link=new;
        rear=new;
        rear->link=front;
    }
    printf("The element %d is inserted into the queue :)\n",data);
}

void delete(){
        struct node *ptr=front;
    if(front==NULL && rear==NULL) printf("Oops! The queue is empty :(\n");
    else if(front==rear){
        front=rear=NULL;
        printf("The element %d is deleted :)\n",ptr->data);
        free(ptr);
    }
    else{
        printf("The element %d is deleted :)\n",front->data);
        front=front->link;
        rear->link=front;
        free(ptr);
    }
}

void print(){
    struct node* ptr=front;
    if(front==rear && rear==NULL) printf("The queue is empty :(\n");
    else{
        printf("queue is:\n");
        while(ptr->link!=front){
            printf("\t%d\n",ptr->data);
            ptr=ptr->link;
        }
        printf("\t%d\n",ptr->data);
    }
}

void peep(){
    if(front==rear && rear==NULL) printf("The queue is empty :(\n");
    else printf("The front element is: %d\n",front->data);
}

int main(){
    for(int i=1;i<8;i++) insert(i);
    print();
    for(int i=0;i<5;i++) delete();
    print();
    peep();
    delete();
    print();
    peep();
    insert(90);
    print();
    peep();
    delete();
    insert(100);
    print();
    peep();
    return 0;
}
