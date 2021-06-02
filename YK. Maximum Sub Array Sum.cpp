#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,sum=0,maximum=0;
    cout<<"Enter no.of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=max(arr[i],sum+arr[i]);
        if(maximum<sum) maximum=sum;
    }
    cout<<"The maximum subarray sum is: "<<maximum;
    return 0;
}
