#include<iostream>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode*next;
}ListNode;

ListNode*head=NULL;

void insert(int val){
    ListNode* ptr=(ListNode*)malloc(sizeof(ListNode));
    ptr->val=val;
    ptr->next=NULL;
    if(head==NULL) head=ptr;
    else{
       ListNode* arr=head;
       while(arr->next!=NULL) arr=arr->next;
       arr->next=ptr;
    }
}

void swapNodes(int k) {
        ListNode*first=NULL,*end=NULL,*cur=head;
        int i=0;
        while(cur){
            i++;
            if(end!=NULL)end=end->next;
            if(i==k) first=cur,end=head;
            cur=cur->next;
        }
        swap(first->val,end->val);
    }

void display(){
    ListNode*ptr=head;
    while(ptr!=NULL){
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    for(int i=1;i<=6;i++) insert(i);
    cout<<"Original Linked List: \n";
    display();
    swapNodes(2);
    cout<<"Swapped Linked List: \n";
    display();
    return 0;
}
