// link: https://codeforces.com/problemset/problem/1373/B

#include<iostream>
using namespace std;

void res(string s){
    int i=0,a=0,b=1;
    while(s[i] && i<s.length()-1){
        if(s[i]!=s[i+1]){
            s.erase(i,2);
            a=a?0:1;
            b=b?0:1;
            i=-1;
        }
        i++;
    }
    if(a) cout<<"DA\n";
    else cout<<"NET\n";
}

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        res(s);
    }
    return 0;
}
