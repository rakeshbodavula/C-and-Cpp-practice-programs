#include<stdio.h>
#include<stdlib.h>

struct node{
     int val;
     struct node *link;
 };

 struct node*front=NULL;
 struct node *rear=NULL;

 void enqueue(int data){
     struct node*new=(struct node*)malloc(sizeof(struct node));
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
 }
 
 void display(){
     if(front==rear && rear==NULL) printf("The queue is empty\n");
     else{
         printf("The queue is: \n");
         struct node*ptr=front;
         while(ptr->link!=front){
             printf(" %d ",ptr->val);
            ptr=ptr->link;
         }
         printf(" %d\n",ptr->val);
     }
 }
 
 void reverse_CQ(){
    struct node *prev, *cur, *next, *last;
	if(front== NULL){
        printf("Cannot reverse empty list.\n");
        return;
    }
    last = front;
    prev  = front;
    cur   = (front)->link;
    front = (front)->link;
    while (front != last){
       front = (front)->link;
        cur->link = prev;
        prev = cur;
        cur  = front;
    }
    cur->link = prev;
    front= prev;
    rear=last;
}
 
 int main(){
 	for(int i=0;i<10;i++) enqueue(i+1);
 	printf("Before reversing ");
 	display();
 	printf("After reversing ");
 	reverse_CQ();
 	display();
 	printf("Time Complexity for reversing is O( n ) where n is no.of nodes\n");
 }
