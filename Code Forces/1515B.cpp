// link: https://codeforces.com/contest/1515/problem/B

#include<bits/stdc++.h>
using namespace std;
int perfect(int a,int x){
  int b=sqrt(a/x);
  return b*b*x==a;
}
int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    if(n%2==0 && perfect(n,2)) cout<<"YES\n";
    else if(n%4==0 && perfect(n,4)) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
