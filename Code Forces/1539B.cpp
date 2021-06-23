// link: https://codeforces.com/contest/1539/problem/B

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long
 
void solve(){
    ll n,q,l,r;
    cin>>n>>q;
    string arr;
    cin>>arr;
    int a[n];
    a[0]=arr[0]-96;
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+arr[i]-96;
    }
    while(q--){
        cin>>l>>r;
        if(l==1) cout<<a[r-1]<<"\n";
        else cout<<a[r-1]-a[l-2]<<"\n";
    }
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
