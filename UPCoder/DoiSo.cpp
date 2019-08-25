#include<iostream>
using namespace std;
typedef long long int ll;

ll ucln (ll a, ll b){
    if(a==0&&b==0) return 0;
    ll r;
    while(b!=0){
        r=a%b;a=b;b=r;
    }
    return a;
}

void xuly (double n){
    ll k=1;
    while(n!=(ll)n){
        n*=10;k*=10;
    }
    ll a=n,b=k;
    k=ucln(a,b);
    a/=k;b/=k;
    if(a%b==0) cout<<a/b;
    else cout<<a<<"/"<<b;
}

int main(){
    double n;
    cin>>n;
    xuly(n);
    return 0;
}
