// link: https://codeforces.com/problemset/problem/746/B

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long

void solve(){
    ll n;
    cin>>n;
    string arr,res;
    cin>>arr;    
    loop(i,0,n){
        if((n-i)%2) res+=arr[i];
        else res=arr[i]+res;
    }
    cout<<res;
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
