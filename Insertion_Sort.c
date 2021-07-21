#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort_non_increasing(int a[],int n){
    int key,k;
    for(int i=1;i<n;i++){
        key=a[i];
        k=i-1;
        while(k<n && a[k]<key){
            a[k+1]=a[k];
            k--;
        }
        a[k+1]=key;
    }
    printf("\nNon - increasingly Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}


void insertion_sort_non_decreasing(int a[],int n){
    int key,k;
    for(int i=1;i<n;i++){
        key=a[i];
        k=i-1;
        while(k>=0 && a[k]>key){
            a[k+1]=a[k];
            k--;
        }
        a[k+1]=key;
    }
    printf("\nNon - decreasingly Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}

int main(){
    srand(time(0));
    int n=10;
    int a[n];
    printf("Random values: ");
    for(int i=0;i<n;i++) a[i]=rand()%50+1,printf("%d ",a[i]);
    insertion_sort_non_decreasing(a,n);
    insertion_sort_non_increasing(a,n);
    return 0;
}