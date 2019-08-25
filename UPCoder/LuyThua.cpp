#include<iostream>
using namespace std;
typedef unsigned long long int ll;
ll modadd(ll a,ll b,ll m){
    return (a%m+b%m)%m;
}
ll modmul(ll a,ll b,ll m){
    a%=m;b%=m;
    ll res=0;
    while(b){
        if(b%2) res=modadd(res,a,m);
        a=modadd(a,a,m);
        b/=2;
    }
    return res;
}
ll modpow(ll a,ll b,ll m){
    a%=m;
    ll res=1;
    while(b){
        if(b%2) res=modmul(res,a,m);
        a=modmul(a,a,m);
        b/=2;
    }
    return res;
}
int main(){
    ll x,y,m;
	do
	{
		cin>>x>>y>>m;
	}
	while(x<0||y<0||m<1);
	cout<<modpow(x,y,m);
	return 0;
}
