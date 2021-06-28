// link: https://codeforces.com/problemset/problem/567/A

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long


void solve(){
    ll n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<arr[1]-arr[0]<<" "<<arr[n-1]-arr[0]<<"\n";
    for(int i=1;i<n-1;i++){
    cout<<min(arr[i]-arr[i-1],arr[i+1]-arr[i])<<" "<<max(arr[i]-arr[0],arr[n-1]-arr[i])<<"\n";
    }
    cout<<arr[n-1]-arr[n-2]<<" "<<arr[n-1]-arr[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
