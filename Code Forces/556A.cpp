// link: https://codeforces.com/problemset/problem/556/A

#include<bits/stdc++.h>
using namespace std;
int main(){
    int len;
    cin>>len;
    string arr;
    cin>>arr;
    int sum=count(arr.begin(),arr.end(),'0');
    if(2*sum<=len) cout<<(len-2*sum);
    else cout<<(len-2*(len-sum));
    return 0;
}
