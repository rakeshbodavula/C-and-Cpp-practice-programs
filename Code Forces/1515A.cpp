// link: https://codeforces.com/contest/1515/problem/A

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int arr[n],sum=0;
        for(int j=0;j<n;j++) cin>>arr[j];
        sort(arr,arr+n);
        int i;
        if(accumulate(arr,arr+n,0)==x) cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(i=0;i<n;i++){
                sum+=arr[i];
                if(sum==x){
                    sum+=arr[i+1]-arr[i];
                    swap(arr[i+1],arr[i]);
                }
                cout<<arr[i]<<" ";
            }
        }
    }
    return 0;
}
