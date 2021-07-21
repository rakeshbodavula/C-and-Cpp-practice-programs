#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *p,int *q){
    *p=*p+*q-(*q=*p);
}

void bubble_non_decreasing(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
        }
    }
    printf("\nNon-decreasing array: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}

void bubble_non_increasing(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]) swap(&a[j],&a[j+1]);
        }
    }
    printf("\nNon-increasing array: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}

int main(){
    srand(time(0));
    int n=10;
    int a[n];
    printf("Random values: ");
    for(int i=0;i<n;i++) a[i]=rand()%50+1,printf("%d ",a[i]);
    bubble_non_decreasing(a,n);
    bubble_non_increasing(a,n);
}