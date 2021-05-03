//  problem link: https://codeforces.com/contest/1519/problem/B

#include<iostream>
using namespace std;
int main(){
    int n,m,k,t;
    cin>>t;
    while(t--){
    cin>>n>>m>>k;
    if(k==m*n-1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}
