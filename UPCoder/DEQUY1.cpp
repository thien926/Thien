#include<iostream>
#include<math.h>
using namespace std;
typedef unsigned long long int ll;
void xuat(ll n,ll *a){
    for(ll i=0;i<n;i++) cout<<a[i];
    cout<<endl;
}
void quaylui(ll k,ll n,ll j,ll *a){
    for(ll i=1;i<=k;i++){
        a[j]=i;
        if(j==n-1) xuat(n,a);
        else quaylui(k,n,j+1,a);
    }
}
int main(){
    ll n,k,*a;
    cin>>k>>n;
    a=new ll[n];
    cout<<pow(k,n)<<endl;
    quaylui(k,n,0,a);
    return 0;
}
