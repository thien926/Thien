#include<iostream>
using namespace std;
typedef unsigned long long int ll;
typedef unsigned short int usi;

void xuat(usi *a,ll n){
    for(ll i=0;i<n;i++) cout<<a[i];
    cout<<endl;
}

void quaylui(usi *a,ll n,ll j){
    for(ll i=0;i<2;i++){
        a[j]=i;
        if(j==n-1) xuat(a,n);
        else quaylui(a,n,j+1);
    }
}

int main(){
    ll n;
    usi *a;
    cin>>n;
    a=new usi[n];
    quaylui(a,n,0);
    delete []a;
    return 0;
}
