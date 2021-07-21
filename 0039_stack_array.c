#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;

void push(int data){
    if(top+1==max) printf("Sorry! the stack is full :(\n\n");
    else{
        top++;
        stack[top]=data;
    printf("Hurray! the element has been inserted into the stack :)\n\n");
    }
}

void pop(){
    if(top<0) printf("Oops! the stack is empty :(\n\n");
    else{
        printf("Hurray! the element ' %d ' is popped out from the stack :)\n\n",stack[top]);
        top--;
    }
}

void print_stack(){
    printf("\nThe stack is: \n\n    --> |     |\n\t-------\n");
    for(int i=top;i>=0;i--){
        printf("\t|  %d  |\n",stack[i]);
        printf("\t-------\n");
    }
    printf("\n");
}

int main(){
    srand(time(0));
    int choice,data,n;
    while(1){
        printf("Please Enter: 0-->enter element into stack\n");
        printf("              1-->delete element\n");
        printf("              2-->see the stack\n");
        printf("              3-->to create a stack of ' n ' elements\n");
        printf("              4-->exit program\n");
        printf("\nYour choice: ");
        scanf("%d",&choice);
        if(choice==0){
            printf("Enter the element to be pushed into the stack: ");
            scanf("%d",&data);
            push(data);
        }
        else if(choice==1) pop();
        else if(choice==2) print_stack();
        else if(choice==3){
            printf("Enter the value of n: ");
            scanf("%d",&n);
            for(int i=0;i<n;i++) push(rand()%10);
            print_stack();
        }
        else{
            printf("Thanks for running my program :)\n\tHave a good day!\n\n");
            break;
        }
    }
    return 0;
}