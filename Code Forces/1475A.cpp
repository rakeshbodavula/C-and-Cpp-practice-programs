// link: https://codeforces.com/contest/1475/problem/A

#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,n,a;
	cin>>t;
	while(t--){
		cin>>n;
		a=n & n-1;  
		if(a) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

/*
      odd*odd=odd
      odd*even=even
      even*odd=even
      even*even=even
      
      Every number has a odd factor>1 untill unless the number is a power of ' 2 ' since the binary form of power of 2 has a single '1' at MSB and remaining zeroes
      and the before number has all ones except at MSB so the AND operation will give zero.
*/
