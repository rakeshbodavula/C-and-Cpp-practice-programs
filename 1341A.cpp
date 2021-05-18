// link: https://codeforces.com/contest/1341/problem/A

#include<iostream>
using namespace std;
void res(int n,int a,int b,int c,int d){
    if(n*(a+b)<c-d || n*(a-b)>c+d) cout<<"No";
    else cout<<"Yes";
}

int main(){
    int n,a,b,c,d,t;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c>>d;
        res(n,a,b,c,d);
        cout<<endl;
    }
    return 0;
}
