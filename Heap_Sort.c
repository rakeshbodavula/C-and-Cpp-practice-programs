#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *p,int *q){
    *p=*p+*q-(*q=*p);
}

void max_heapify(int a[],int index,int size){
    int l=2*index+1,r=l+1,large=index;
    if(l<size && a[l]>a[large]) large=l;
    if(r<size && a[r]>a[large]) large=r;
    if(index!=large){
        swap(&a[index],&a[large]);
        max_heapify(a,large,size);
    }
}

void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) max_heapify(a,i,n);
    for(int i=n-1;i>=0;i--){
        swap(&a[0],&a[i]);
        max_heapify(a,0,i);
    }
}

int main(){
    srand(time(0));
    int n=10;
    int a[n];
    printf("Random values: ");
    for(int i=0;i<n;i++) a[i]=rand()%50+1,printf("%d ",a[i]);
    heap_sort(a,n);
    printf("\nSorted values: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}