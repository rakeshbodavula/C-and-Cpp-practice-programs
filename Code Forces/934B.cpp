// link: https://codeforces.com/contest/934/problem/B

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long

void solve(){
    ll n;
    cin>>n;
    if(n>36){
        cout<<-1;
        return;
    }
    for(int i=0;i<n/2;i++) cout<<"8";
    if(n%2) cout<<"4";
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
