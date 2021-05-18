// link: https://codeforces.com/problemset/problem/149/A

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(int k,vector<int>arr){
    if(k==0) return 0;
    int sum=0;
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i=0;i<12;i++){
        sum+=arr[i];
        if(sum>=k) return i+1;
    }
    return -1;
}

int main(){
    int k;
    cin>>k;
    vector<int>arr(12);
    for(int i=0;i<12;i++) cin>>arr[i];
    cout<<func(k,arr);
    return 0;   
}
