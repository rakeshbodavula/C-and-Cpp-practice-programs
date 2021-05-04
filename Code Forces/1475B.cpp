//  link: https://codeforces.com/problemset/problem/1475/B

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,sum=0;
	cin>>t;
	while(t--){
		cin>>n;
		if((2021*(n%2020))>n) cout<<"NO\n";
		else if((n-(2021*(n%2020)))%2020!=0) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
