//                          1-->Pass by Reference method

#include<stdio.h>
#include<stdlib.h>

struct stack{
	int front;
	struct stack *next;
};

void push(int n,struct stack **head){
	struct stack *ptr=malloc(sizeof(struct stack));
	if(*head==NULL){
		(*head)->front=n;
		(*head)->next=NULL;
	}
	else{
		ptr->front=n;
		ptr->next=*head;
		*head=ptr;
	}
}

void pop(struct stack **head){
	struct stack* ptr=*head;
	if(*head==NULL){
		printf("The stack is empty :(\n");
	}
	else{
		*head=(*head)->next;
		free(ptr);
	}
}

void print(struct stack* head){
	while(head->next!=NULL){
		printf("%d\n",head->front);
		head=head->next;
	}
}

int main(){
	struct stack* head=malloc(sizeof(struct stack));
	push(2,&head);
	push(3,&head);
	push(4,&head);
	push(5,&head);
	push(6,&head);
	push(8,&head);
	printf("Stack is: \n");
	print(head);
	printf("popped\n");
	pop(&head);
	pop(&head);
	pop(&head);
	push(99,&head);
	print(head);
	return 0;
}

//================================================================================================================================================

                                                2-->Pass by value method
                                                
#include<stdio.h>
#include<stdlib.h>

struct stack{
	int front;
	struct stack *next;
};

struct stack* push(int n,struct stack *head){
	struct stack *ptr=malloc(sizeof(struct stack));
	if(head==NULL){
		head->front=n;
		head->next=NULL;
	}
	else{
		ptr->front=n;
		ptr->next=head;
		head=ptr;
	}
	return head;
}

struct stack* pop(struct stack *head){
	struct stack* ptr=head;
	if(head==NULL){
		printf("The stack is empty :(\n");
	}
	else{
		head=head->next;
		free(ptr);
	}
	return head;
}

void print(struct stack* head){
	while(head->next!=NULL){
		printf("%d\n",head->front);
		head=head->next;
	}
}

int main(){
	struct stack* head=malloc(sizeof(struct stack));
	head=push(2,head);
	head=push(3,head);
	head=push(4,head);
	head=push(5,head);
	head=push(6,head);
	head=push(8,head);
	printf("Stack is: \n");
	print(head);
	printf("popped\n");
	head=pop(head);
	head=pop(head);
	print(head);
	return 0;
}
