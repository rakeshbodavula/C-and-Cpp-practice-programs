#include<stdio.h>
 #define max 10
 int queue[max];
 int front=-1,rear=-1;

 void insert(int data){
     if(front==rear && rear==-1){
         front=0;
         queue[++rear]=data;
         printf("The element %d is inserted at the starting of queue :)\n",data);
     }
     else if((rear+1)%max==front) printf("Oops! The queue is full :(\n");
     else{
        rear=(rear+1)%max;
        queue[rear]=data;
        printf("The element %d is inserted into the queue :)\n",data);
     }  
}

void delete(){
    if(front==rear && rear==-1) printf("Oops! The queue is empty :(\n");
    else if(front==rear){
        printf("The element %d is deleted from the queue :)\n",queue[front]);
        front=-1,rear=-1;
    }
    else{
        printf("The element %d is deleted from the queue :)\n",queue[front]);
        front=(front+1)%max;
    }
}

void print(){
    int i=front;
    if(i<0) printf("The queue is empty\n");
    else{
        while(i<=rear){
            printf("%d\n",queue[i]);
            if(i==rear) break;
            i=(i+1)%max;
        }
    }
}

void peep(){
    if(front==rear && rear==-1) printf("The queue is empty :(\n");
    else printf("The front element is: %d\n",queue[front]);
}

int main(){
    for(int i=0;i<10;i++) insert(i);
    print();
    for(int i=0;i<7;i++) delete();
    print();
    peep();
    delete();
    print();
    peep();
}
