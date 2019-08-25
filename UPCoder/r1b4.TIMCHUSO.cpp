//Công th?c: Uk = 10 * (a * 10 mu(k-1) % b) / b
#include<iostream>
using namespace std;
typedef unsigned long long int ll;
ll mod_phep_cong(ll a,ll b,ll m){
	return (a%m+b%m)%m;
}
ll mod_phep_nhan(ll a,ll b,ll m){
	ll res=0;
	a%=m;b%=m;
	while(b){
		if(b%2) res=mod_phep_cong(res,a,m);
		a=mod_phep_cong(a,a,m);
		b/=2;
	}
	return res;
}
ll mod_phep_mu(ll a,ll b,ll m){
	a%=m;
	ll res=1;
	while(b){
		if(b%2) res=mod_phep_nhan(res,a,m);
		a=mod_phep_nhan(a,a,m);
		b=b/2;
	}
	return res;
}
int main(){
	ll a,b,k,c;
	cin>>a>>b>>k;
	c=mod_phep_mu(10,k-1,b);
//	cout<<c<<endl;
	cout<<10*mod_phep_nhan(a,c,b)/b<<endl;
	return 0;
}
