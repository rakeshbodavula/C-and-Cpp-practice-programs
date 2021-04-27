/* Explanation:
                The maximum number that can be stored by the int variable is INT_MAX = 2^31 - 1.
                The number which is power of 3 and is nearest and less than INT_MAX is 1,16,22,61,467 = 3^19.
                So, any number which is power of 3 must divide 1,16,22,61,467.
*/
#include<iostream>
#include<cmath>
using namespace std;
int power_check(int n){
    if(n<=0) return 0;
    else return (1162261467%n==0);
}
int main(){
    int n;
    cout<<"enter a number to check if it is power of 3: ";
    cin>>n;
    if(power_check(n)) cout<<"Yes\n";
    else cout<<"No\n";
}
