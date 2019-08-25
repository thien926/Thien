#include<iostream>
using namespace std;
typedef unsigned long long int ll;

void nhap(ll &n,int *&a){
  cin>>n;
  a=new int [n];
}

void xuat(ll n,int *a){
  for(ll i=0;i <n;i++) cout<<a[i]<<" ";
  cout<<endl;
}

void backtring(ll n,int *a,ll j){
  for(int i=0;i <2;i++){
    a [j]=i;
    if(j==n-1) xuat(n,a);
    else backtring(n,a,j+1);
  }
}

int main(){
  ll n;
  int *a;
  nhap(n,a);
  backtring(n,a,0);
  delete []a;
  return 0;
}
