// link: https://codeforces.com/problemset/problem/1354/A

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long


void solve(){
    ll a,b,c,d,x;
    cin>>a>>b>>c>>d;
    if(a>b && c<=d){
        cout<<-1<<"\n";
        return;
    }
    if(a<=b){
        cout<<b<<"\n";
        return;
    }
    x=(a-b)/(c-d);
    if(x*(c-d)<(a-b)){
        while(x*(c-d)<(a-b)) x++;
    }
    cout<<x*c+b<<"\n";
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
