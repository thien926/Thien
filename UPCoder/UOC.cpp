#include<iostream>
using namespace std;
typedef unsigned long long int ll;
int main(){
    ll n;
    cin>>n;
    ll k=n/2;
    for(ll i=1;i<=k;i++) if(n%i==0) cout<<i<<endl;
    cout<<n;
    return 0;
}
