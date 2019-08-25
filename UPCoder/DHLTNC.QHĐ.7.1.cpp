#include<iostream>
using namespace std;
typedef unsigned long long int ll;

ll fi(ll n){
  if(n<=2) return 1;
  ll f1=1,f2=1,f3,d=2;
  do{
    f3=f1+f2;f1=f2;f2=f3;d++;
  }
  while(d<n);
  return f3;
}

int main(){
    ll n;
    cin>>n;
    cout<<fi(n);
    return 0;
}
