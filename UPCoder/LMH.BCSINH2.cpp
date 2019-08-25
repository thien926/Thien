#include<iostream>
using namespace std;
typedef unsigned long long int ll;

void nhap(ll &k,ll &n,ll *&a){
  cin>>k>>n;
  a=new ll [n+1];a [0]=0;
}

void xuat(ll n,ll *a){
  for(ll i=1;i <=n;i++) cout<<a[i]<<" ";
  cout<<endl;
}

void backtring(ll k,ll n,ll *a,ll j){
  for(ll i=1;i <=k;i++) if(i >a [j-1]){
    a [j]=i;
    if(j==n) xuat(n,a);
    else backtring(k,n,a,j+1);
  }
}

int main(){
  ll k,n,*a;
  nhap(k,n,a);
  backtring(k,n,a,1);
  delete []a;
  return 0;
}
