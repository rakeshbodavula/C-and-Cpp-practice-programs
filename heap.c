#include<stdio.h>
int arr[100],n;

void insert(int data,int pos){
    int parent;
    while(pos>0){
        parent=(pos-1)/2;
        if(data <= arr[parent]){
            arr[pos]=data;
            return;
        }
            arr[pos]=arr[parent];
            pos=parent;
    }
    arr[0]=data;    // first element in the heap.
}

void deletion(int num){
    int left,right,temp,parent,i;
    for(i=0;i<n;i++){
        if(num==arr[i]) break;
    }
    if(arr[i]!=num){
        printf("%d not in heap\n",num);
        return;
    }
    arr[i]=arr[n-1];
    n--;
    parent=(i-1)/2;
    if(arr[i] > arr[parent]){
        insert(arr[i],i);
        return;
    }
    left=2*i+1;
    right=2*i+2;
    while(right < n){
        if(arr[i] >= arr[left] && arr[i] >= arr[right]) return;
        if(arr[right] <= arr[left]){
            temp=arr[i];
            arr[i]=arr[left];
            arr[left]=temp;
            i=left;
        }
        else{
            temp=arr[i];
            arr[i]=arr[right];
            arr[right]=temp;
            i=right;
        }
        left=2*i+1;
        right=2*i+2;
    }
    if(left==n-1 && arr[i] < arr[left]){
        temp=arr[i];
        arr[i]=arr[left];
        arr[left]=temp;
    } 
}

void print(){
    if(!n) printf("\nNo element\n");
    else printf("\nThe heap is: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

int main(){
    int num,element;
    n=0;
    printf("Enter the no.of nodes in the heap: ");
    scanf("%d",&num);
    for(n=0;n<num;n++){
        scanf("%d",&element);
        insert(element,n);
    }
    print();
    printf("\nEnter the element to be deleted: ");
    scanf("%d",&element);
    deletion(element);
    print();
    return 0;
}