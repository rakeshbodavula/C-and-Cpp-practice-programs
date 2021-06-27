// link: https://codeforces.com/problemset/problem/1462/C

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long


void solve(){
    int x;
    cin>>x;
    if(x>45) cout<<-1<<"\n";
    else if(x<10) cout<<x<<"\n";
    else if(x<18) cout<<x-9<<9<<"\n";
    else if(x<25) cout<<x-17<<89<<"\n";
    else if(x<31) cout<<x-24<<789<<"\n";
    else if(x<36) cout<<x-30<<6789<<"\n";
    else if(x<40) cout<<x-35<<56789<<"\n";
    else if(x<43) cout<<x-39<<456789<<"\n";
    else if(x<45) cout<<x-42<<3456789<<"\n";
    else if(x<46) cout<<x-44<<23456789<<"\n";
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
