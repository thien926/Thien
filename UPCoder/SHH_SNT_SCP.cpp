#include<iostream>
#include<math.h>
using namespace std;
typedef unsigned long long int ll;

bool sohoanhao(ll n){
    ll i,k=n/2,tong=0;
    for(i=1;i<=k;i++) if(n%i==0) tong=tong+i;
    if(tong==n) return true;
    return false;
}

bool snt(ll n){
    if(n<2) return false;
    ll i,k=sqrt(n);
    for(i=2;i<=k;i++) if(n%i==0) return false;
    return true;
}

bool sochinhphuong(ll n){
    ll k=sqrt(n);
    if(k==sqrt(n)) return true;
    return false;
}
int main(){
    int n;
    ll x;
    cin>>n>>x;
    switch(n){
        case 1:if(sohoanhao(x)) cout<<"yes";else cout<<"no";break;
        case 2:if(snt(x)) cout<<"yes";else cout<<"no";break;
        case 3:if(sochinhphuong(x)) cout<<"yes";else cout<<"no";break;
    }
    return 0;
}
