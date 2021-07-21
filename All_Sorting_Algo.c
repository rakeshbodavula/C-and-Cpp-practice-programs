#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *p,int *q){
    *p=*p+*q-(*q=*p);
}

void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int k=i-1,key=a[i];
        while(a[k]>key && k>=0){
            a[k+1]=a[k];
            k--;
        }
        a[k+1]=key;
    }
}

void selection_sort(int a[],int n){
    for(int i=0;i<n;i++){
        int min=a[i],index=i;
        for(int j=i+1;j<n;j++){ 
            if(a[j]<min) min=a[j],index=j;
        }
        swap(&a[index],&a[i]);
    }
}

void bubble_sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(&a[j],&a[j+1]); 
        }
    }
}

void merge(int a[],int l,int m,int r){
    int x=0,y=0,k=l,n1=m-l+1,n2=r-m;
    int lft[n1],rgt[n2];
    for(int i=0;i<n1;i++) lft[i]=a[l+i];
    for(int i=0;i<n2;i++) rgt[i]=a[m+1+i];
    while(x<n1 && y<n2){
        if(lft[x]<=rgt[y]) a[k++]=lft[x++];
        else a[k++]=rgt[y++];
    }
    while(x<n1) a[k++]=lft[x++];
    while(y<n2) a[k++]=rgt[y++];
}

void merge_sort(int a[],int l,int r){
    if(l<r){
        int m= l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    srand(time(0));
    int a[]={-45,0,8,1,-99,87,56,45,55,-101};
    int n=sizeof(a)/sizeof(a[0]);
    printf("Random values: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);

    insertion_sort(a,n);
    printf("\nInsertion sorted values: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);


    selection_sort(a,n);
    printf("\nselection sorted values: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);


    bubble_sort(a,n);
    printf("\nBubble sorted values: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);


    merge_sort(a,0,n-1);
    printf("\nmerge sorted values: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}