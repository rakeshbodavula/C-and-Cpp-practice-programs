#include<stdio.h>

int Bin_Search(int arr[],int L,int U,int key){
    while(L<=U){
        int mid=(L+U)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) L=mid+1;
        else U=mid-1;
    }
    return -1;
}
int main(){
    int n;
    printf("No.of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("The elements in the sorted array are: \n");
    for(int i=0;i<n;i++) arr[i]=i+1,printf("%d ",arr[i]);
    int key;
    printf("\nEnter key: ");
    scanf("%d",&key);
    int res=Bin_Search(arr,0,n-1,key);
    printf("the key is found at index: %d  ",res);
    if(res<0) printf("It means key is not found\n");
    return 0;
}
