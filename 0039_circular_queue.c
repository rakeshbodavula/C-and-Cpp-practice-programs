//      Circular Queue using Array

#include<stdio.h>
#define max 5
int queue[max];
int front=-1,rear=-1;

void enqueue(int val){
    if((rear+1)%max==front) printf("The queue is full\n");
    else if(front==rear && rear==-1){
        front=rear=0;
        queue[front]=val;
        printf("The value %d is inserted at the beginning of the queue \n",val);
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=val;
        printf("The value %d is inserted into the queue \n",val);
    }
}

void dequeue(){
    if(front==rear && rear==-1) printf("The queue is empty\n");
    else if(front==rear){
        printf("The element %d is deleted \n",queue[front]);
        front=-1,rear=-1;
    }
    else{
        printf("The element %d is deleted \n",queue[front]);
        front=(front+1)%max;
    }
}

void peep(){
    if(front==rear && rear==-1) printf("The queue is empty\n");
    else{
        printf("The front element is: %d\n",queue[front]);
    }
}

void display(){
    if(front==rear && rear==-1) printf("The queue is empty\n");
    else{
        int i=front;
        printf("The queue is: \n");
        while(i!=rear){
            printf("\t%d\n",queue[i]);
            i=(i+1)%max;
        }
        printf("\t%d\n",queue[rear]);
    }
}

int main(){
    printf("This is the implementation of circular queue using Array\n");
    for(int i=1;i<6;i++) enqueue(i);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    peep();
    enqueue(30);
    enqueue(50);
    display();
    peep();
    dequeue();
    display();
    peep();
    printf("Thanks! for running my program :)\n");
    return 0;
}


/*

//====================================================Circular Queue using Linked List====================================================

#include<stdio.h>
#include<stdlib.h>
 struct node{
     int val;
     struct node *link;
 };

 struct node*front=NULL;
 struct node *rear=NULL;

 void enqueue(int data){
     struct node *new=(struct node*)malloc(sizeof(struct node));
     new->val=data;
     new->link=NULL;
     if(front==rear && rear==NULL){
         front=new;
         rear=new;
     }
     else{
         new->link=front;
         rear->link=new;
         rear=new;
     }
     printf("The value %d is inserted into the queue \n",rear->val);
 }

 void dequeue(){
     struct node*ptr=front;
     if(front==rear && rear==NULL) printf("The queue is empty\n");
     else if(front==rear){
         front=NULL;
         rear=NULL;
         printf("The element %d is deleted from the queue\n",ptr->val);
         free(ptr);
     }
     else{
        front=front->link;
        rear->link=front;
        printf("The element %d is deleted from the queue\n",ptr->val);
        free(ptr);
     }
 }

 void peep(){
     if(front==rear && rear==NULL) printf("The queue is empty\n");
     else{
         printf("The front element is: %d\n",front->val);
     }
 }

 void display(){
     if(front==rear && rear==NULL) printf("The queue is empty\n");
     else{
         printf("The queue is: \n");
         struct node*ptr=front;
         while(ptr->link!=front){
             printf("\t%d\n",ptr->val);
            ptr=ptr->link;
         }
         printf("\t%d\n",ptr->val);
     }
 }

 int main(){
     printf("This is implementation of circular queue using Linked List\n");
    for(int i=1;i<7;i++) enqueue(i);
    display();
    for(int i=0;i<4;i++) dequeue();
    display();
    peep();
    enqueue(30);
    enqueue(50);
    display();
    peep();
    dequeue();
    display();
    peep();
    printf("Thanks! for running my program :)\n");
    return 0;
 }
 */