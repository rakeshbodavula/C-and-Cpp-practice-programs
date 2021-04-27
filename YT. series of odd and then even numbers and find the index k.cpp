/*  General series is 1,2,3,4,5,.......n
    But oddeven series is 1,3,5,7,9,....2,4,6,8,.......
    In this oddeven series we need to find the number in index 'k'.
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    if(k<=(n+1)/2) cout<<2*k-1;
    else cout<<2*(k-(n+1)/2);
    return 0;
}
