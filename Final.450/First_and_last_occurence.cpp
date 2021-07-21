// link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x ){
    vector<int>res;
    int cnt=count(arr,arr+n,x);
    if(cnt>0)
        res.push_back(find(arr,arr+n,x)-arr);
    else res.push_back(-1);
    if(cnt>0) res.push_back(res[0]+cnt-1);
    else res.push_back(-1);
    return res;
}

int main(){
    int t;
    cout<<"Enter t: ";
    cin>>t;
    while(t--)
    {
        int n,x;
        cout<<"Enter n and x: ";
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
