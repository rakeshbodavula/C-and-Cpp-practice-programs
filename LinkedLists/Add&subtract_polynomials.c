#include<stdio.h>
#include<stdlib.h>

struct node{
	int coefficient;
	int power;
	struct node* link;
};

struct node* create_polynomial(){
	struct node*head,*ptr;
	int n;
	printf("Enter no.of terms in the polynomial: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(i==0){
			head=(struct node*)malloc(sizeof(struct node));
			ptr=head;
		}
		else{
			ptr->link=(struct node*)malloc(sizeof(struct node));
			ptr=ptr->link;
			}
			printf("Enter coefficient of term %d : ",i+1);
			scanf("%d",&ptr->coefficient);
			printf("Enter power of the term %d : ",i+1);
			scanf("%d",&ptr->power);
	}
	ptr->link=NULL;
	return head;
}

void print_polynomial(struct node *head){
	while(head!=NULL){
		printf("%dx^%d",head->coefficient,head->power);
		if(head->link!=NULL && head->link->coefficient>=0) printf(" + ");
		else printf(" ");
 		head=head->link;
	}
	printf("\n");
}

void add_polynomial(struct node* p1,struct node* p2,struct node* sum){
	while(p1!=NULL && p2!=NULL){
		if(p1->power > p2->power){
			sum->power=p1->power;
			sum->coefficient=p1->coefficient;
			p1=p1->link;
		}
		else if(p1->power < p2->power){
			sum->power=p2->power;
			sum->coefficient=p2->coefficient;
			p2=p2->link;
		}
		else{
			sum->power=p1->power;
			sum->coefficient=p1->coefficient + p2->coefficient;
			p1=p1->link;
			p2=p2->link;
		}
		if(p1 ||p2){
		sum->link=(struct node*)malloc(sizeof(struct node));
		sum=sum->link;
		sum->link=NULL;
		}
	}
	while(p1!=NULL || p2!=NULL){
		if(p1){
			sum->coefficient=p1->coefficient;
			sum->power=p1->power;
			p1=p1->link;
		}
		if(p2){
			sum->coefficient=p2->coefficient;
			sum->power=p2->power;
			p2=p2->link;
		}
        if(p1||p2){
		sum->link=(struct node*)malloc(sizeof(struct node));
		sum=sum->link;
        }
	}
    sum->link=NULL;
	printf("Polynomial added\n");
}

void subtract_poly(struct node* p1,struct node*p2,struct node*sub){
    while(p1 && p2){
        if(p1->power > p2->power){
            sub->power=p1->power;
            sub->coefficient=p1->coefficient;
            p1=p1->link;
        }
        else if(p1->power < p2->power){
            sub->power=p2->power;
            sub->coefficient=-(p2->coefficient);
            p2=p2->link;
        }
        else {
            sub->power=p1->power;
            sub->coefficient=p1->coefficient - p2->coefficient;
            p1=p1->link;
            p2=p2->link;
        }
		if(p1 || p2){
			sub->link=(struct node*)malloc(sizeof(struct node));
			sub=sub->link;
			sub->link=NULL;
		}
    }
    while(p1 || p2){
        if(p1){
            sub->power=p1->power;
            sub->coefficient=p1->coefficient;
            p1=p1->link;
        }
        else if(p2){
            sub->power=p2->power;
            sub->coefficient=-p2->coefficient;
            p2=p2->link;
        }
        if(p1||p2){
            sub->link=(struct node*)malloc(sizeof(struct node));
            sub=sub->link;
            sub->link=NULL;
        }
    }
    sub->link=NULL;
}

int main(){
	struct node* polynomial1,*polynomial2;
	struct node *sum=(struct node*)malloc(sizeof(struct node));
    struct node *sub=(struct node*)malloc(sizeof(struct node));
	polynomial1=create_polynomial();
	polynomial2=create_polynomial();
	printf("The polynomial 1 is: ");
	print_polynomial(polynomial1);
	printf("The polynomial 2 is: ");
	print_polynomial(polynomial2);
	add_polynomial(polynomial1,polynomial2,sum);
	printf("Sum of Polynomials is: ");
	print_polynomial(sum);
    subtract_poly(polynomial1,polynomial2,sub);
	printf("Difference of Polynomials is: ");
    print_polynomial(sub);
	return 0;
}
