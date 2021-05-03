// link: https://codeforces.com/problemset/problem/460/A

#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main(){
    int n,m,count,i=1;
    cin>>n>>m;
    count=n;
    while(i){
        if(i%m==0) count++;
        count--;
        if(count==0){
            cout<<i;
            break;
        }
        i++;
    }
    return 0;
}
