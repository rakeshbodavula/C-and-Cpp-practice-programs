#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue[max];
int front=0,rear=-1;

int isfull(){
    if(rear==max-1) return 1;
    else return 0;
}


int isempty(){
    if(front<0 || front>rear) return 1;
    else return 0;
}

void add_to_queue(int data){
    if(isfull()) printf("Sorry! The queue is full can't add :(\n\n");
    else{
        rear++;
        queue[rear]=data;
        printf("Yahooo! The element is enqueued :)\n\n");
    }
}

void delete_from_queue(){
    if(isempty()) printf("Ooops! The queue is empty can't delete :(\n\n");
    else{
        printf("Yahooo! The element %d is dequeued :)\n\n",queue[front]);
        front++;
    }
}

void peek(){
    printf("The front element is: %d\n\n",queue[front]);
}

void show(){
    printf("\nThe queue is: \n\nfront-->|  %d  |\n\t-------\n",queue[front]);
    for(int i=front+1;i<=rear;i++){
        if(i==rear) printf("rear-->");
        printf("\t|  %d  |\n",queue[i]);
        if(i<rear) printf("\t-------\n");
    }
    printf("\n");
}


int main(){
    add_to_queue(1);
    add_to_queue(4);
    int choice,a;
    while(1){
        printf("Enter: 0-->Enter elements\n");
        printf("       1-->Delete elements\n");
        printf("       2-->Check if queue is full\n");
        printf("       3-->Check if queue is empty\n");
        printf("       4-->print the front element\n");
        printf("       5-->show queue\n");
        printf("       6-->Exit program\n\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Enter element to be added: ");
                scanf("%d",&a);
                add_to_queue(a);
                break;
            case 1:
                delete_from_queue();
                break;
            case 2:
                if(isfull()) printf("Ooops! The queue is full :(\n\n");
                else printf("The queue is not full :)\n\n");
                break;
            case 3:
                if(isempty()) printf("Oops! The queue is empty :(\n\n");
                else printf("The queue is not empty :)\n\n");
                break;
            case 4:
                peek();
                break;
            case 5:
                show();
                break;
            default:
                break;
        }
        if(choice==6){
            printf("Thanks for running my code :)\n\n");
            printf("Have a good and pleasant day :)\n\n");
            break;
        }
    }
    return 0;
}