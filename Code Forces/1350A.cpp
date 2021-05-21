// link: https://codeforces.com/problemset/problem/1350/A

#include<iostream>
#include<cmath>
using namespace std;

int min_fact(int n){
    int i=2;
    while(i<=sqrt(n)){
        if(n%i==0) return i;
        i++;
    }
    return n;
}

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n%2==0) n+=2*k;
        else n+=min_fact(n)+2*k-2;
        cout<<n<<endl;
    }
}
