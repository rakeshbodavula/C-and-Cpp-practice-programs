// link: https://codeforces.com/problemset/problem/1296/B

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long


void solve(){
    ll a;
    cin>>a;
    ll count=a;
    while(a/10){
        count+=(a/10 ? a/10 : a%10);
        a=(a/10+a%10);
    }
    cout<<count<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}
