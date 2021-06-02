#include<iostream>
using namespace std;
int main(){
    int n,sum=0,max=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        if(sum<0) sum=0;
        if(max<sum) max=sum;
    }
    cout<<"The maximum subarray sum is: "<<max;
    return 0;
}
