#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long int ll;

ll tong (ll n){
    if(n<=0) return 0;
    return n%10 +tong(n/10);
}

int main(){
    ll n; cin>>n;
    n=abs(n);
    cout<<tong(n);
    return 0;
}
